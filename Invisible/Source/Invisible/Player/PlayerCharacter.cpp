// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"

#include "Engine.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Invisible/ActionableObject/Locker.h"
#include "Invisible/Enemy/Enemy.h"
#include "Invisible/Player/PlayerDieEvent.h"
#include "Invisible/System/ConfigParams.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundObject.h"
#include "Invisible/System/SoundSystem.h"
#include "Invisible/System/StencilBitValue.h"
#include "Kismet/GameplayStatics.h"

//コンストラクタ
APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	//カメラを追加する
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	CameraComponent->SetupAttachment(RootComponent);
	CameraComponent->SetRelativeLocation(FVector(30.0f, 0.0f, 80.0f));
	//ポーンがカメラの回転を制御できるように
	CameraComponent->bUsePawnControlRotation = true;

	EnemyDetectArea = CreateDefaultSubobject<UEnemyDetectArea>(TEXT("EnemyDetectArea"));
	EnemyDetectArea->SetupAttachment(RootComponent);

	ActionArea = CreateDefaultSubobject<UPlayerActionArea>(TEXT("ActionArea"));
	ActionArea->SetupAttachment(RootComponent);

	//コンポーネントの衝突時イベントを追加
	this->GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::OnComponentBeginOverlap);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	CurrentActionMode = EPlayerActionMode::Move;
	GetCharacterMovement()->MaxWalkSpeed = MaxMoveSpeed;

	//足元に飛ばすレイの無視リスト
	DetectFootObjectLinetraceQueryParams.AddIgnoredActor(this);
	//敵の音察知コリジョンに引っかかることがあるので追加しておく
	TArray<AActor*> enemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemy::StaticClass(), enemies);
	DetectFootObjectLinetraceQueryParams.AddIgnoredActors(enemies);
}

void APlayerCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//移動中なら歩行音を再生する
	if (CurrentActionMode == EPlayerActionMode::Move)
	{
		PlayWalkSound(DeltaTime);
	}

	//回転制限
	ClampPlayerCameraPitchRotation();
	ClampPlayerCameraYawRotation();

	//敵を検知
	EnemyDetectArea->DetectAndWarn();
	//ロッカーに入っているときに座標を固定する
	FixedLocationIfInLocker();
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//入力にバインドさせる
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::Lookup);
	PlayerInputComponent->BindAction("PlayerAction", EInputEvent::IE_Pressed, this, &APlayerCharacter::InputedActionCommand);
}

void APlayerCharacter::HeardEnemyWalkOnPuddleSound(AEnemy* enemy)
{
	//敵が水たまりを踏んだ時用のステンシル値を設定する
	auto SilhouetteSkeltal = enemy->GetSilhouetteSkeltal();
	const int32 Value = SilhouetteSkeltal->CustomDepthStencilValue | static_cast<int32>(EStencilBitValue::SilhouetteWhenEnemyWalkOnPuddle);
	SilhouetteSkeltal->SetCustomDepthStencilValue(Value);

	//一定時間後にステンシル値を元に戻す
	FTimerManager& TimerManager = GetWorldTimerManager();
	FTimerHandle Handle;
	TimerManager.SetTimer(Handle, [SilhouetteSkeltal]() {
		//シーンを超えたときなどキャプチャが無効になるときの対策
		if (!SilhouetteSkeltal)
			return;
		const int32 Value = SilhouetteSkeltal->CustomDepthStencilValue & ~static_cast<int32>(EStencilBitValue::SilhouetteWhenEnemyWalkOnPuddle);
		SilhouetteSkeltal->SetCustomDepthStencilValue(Value);
	},
	    EnemyVisibleTimeWhenEnemyWalkOnPuddle, false);
}

//前方向への移動
void APlayerCharacter::MoveForward(float Value)
{
	if (CurrentActionMode != EPlayerActionMode::Move)
		return;
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(direction, Value);

	//一定値以上の移動量があれば歩いているとみなす
	if (std::abs(Value) > WalkingThreshold)
	{
		bIsWalking = true;
	}
}

//右方向への移動
void APlayerCharacter::MoveRight(float Value)
{
	if (CurrentActionMode != EPlayerActionMode::Move)
		return;
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(direction, Value);

	//一定値以上の移動量があれば歩いているとみなす
	if (std::abs(Value) > WalkingThreshold)
	{
		bIsWalking = true;
	}
}

//カメラの横方向の回転処理
void APlayerCharacter::Turn(float Amount)
{
	const bool CanTurn =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!CanTurn)
		return;

	const float Coef = UMyGameInstance::GetInstance()->GetConfigParams()->Sensitivity;
	const float YawValue = Coef * Amount * GetWorld()->GetDeltaSeconds();
	AddControllerYawInput(YawValue);
}

//カメラの上下方向の回転処理
void APlayerCharacter::Lookup(float Amount)
{
	const bool CanLookup =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!CanLookup)
		return;

	const float Coef = UMyGameInstance::GetInstance()->GetConfigParams()->Sensitivity;
	const float PitchValue = Coef * Amount * GetWorld()->GetDeltaSeconds();
	AddControllerPitchInput(PitchValue);
}

//衝突開始時に呼ばれる
void APlayerCharacter::OnComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//音オブジェクトなら音が聞こえる範囲内に入ったことを表す
	if (Cast<ASoundObject>(OtherActor))
	{
		HeardSound(Cast<ASoundObject>(OtherActor));
		return;
	}
}

//音が聞こえる範囲内に入った
void APlayerCharacter::HeardSound(ASoundObject* soundObject)
{
	//聞こえた音の種類によって場合分け
	switch (soundObject->getSoundType())
	{
	case ESoundType::Enemy_Walk_On_Puddle:
	{
		AEnemy* Enemy = Cast<AEnemy>(soundObject->getSoundGenerateSource());
		if (Enemy)
		{
			HeardEnemyWalkOnPuddleSound(Enemy);
		}
	}
	break;
	default:
		break;
	}
}

void APlayerCharacter::PlayWalkSound(float DeltaTime)
{
	//歩いているときに一定時間ごとに歩行音再生
	if (bIsWalking)
	{
		//次の移動の入力があるまで歩いていない状態として扱う
		bIsWalking = false;

		WalkingSecond += DeltaTime;

		//歩いている時間が一定量を超えたら再生する
		if (WalkingSecond > WalkingSoundPlayInterval)
		{
			WalkingSecond -= WalkingSoundPlayInterval;

			//足元にレイを飛ばし、床がなんであるか判定する
			FHitResult hit;
			constexpr float LINE_LENGTH = 300.0f;
			const FVector Start = GetActorLocation();
			const FVector End = GetActorLocation() + FVector::DownVector * LINE_LENGTH;
			if (!GetWorld()->LineTraceSingleByChannel(hit, Start, End,
			        ECollisionChannel::ECC_Visibility, DetectFootObjectLinetraceQueryParams))
				return;
			const ESoundType sound = [&hit]() {
				//TODO:GamePlayTagで処理するのが望ましい
				//TODO:床と親クラスを一致させないと難しい
				if (hit.Actor->ActorHasTag(TEXT("Puddle")))
				{
					return ESoundType::Player_Walk_On_Puddle;
				}
				return ESoundType::Player_Walk;
			}();

			const FVector SeLocation = [&]() {
				FVector location = GetActorLocation();
				location.Z = hit.Location.Z;
				return location;
			}();

			UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(sound, SeLocation, this);
		}
	}
	else
	{
		WalkingSecond = 0.0f;
	}
}

//プレイヤーカメラの上下方向の回転制限
void APlayerCharacter::ClampPlayerCameraPitchRotation()
{
	//クランプが必要かどうか判定する
	const bool NeedClamp =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!NeedClamp)
		return;

	//視界の範囲は状態によって変わる
	const FFloatRange Range = [&]() -> FFloatRange {
		switch (CurrentActionMode)
		{
		case EPlayerActionMode::Move:
			return FFloatRange{NormalCameraPitch.GetLowerBoundValue(), NormalCameraPitch.GetUpperBoundValue()};
		case EPlayerActionMode::IsInLocker:
			return FFloatRange{CameraPitchWhenIsInLocker.GetLowerBoundValue(), CameraPitchWhenIsInLocker.GetUpperBoundValue()};
		default:
			return FFloatRange{0.0f, 0.0f};
		}
	}();

	//新しい角度を設定する
	FRotator NewRotation = Controller->GetControlRotation();
	NewRotation.Pitch = FMath::ClampAngle(NewRotation.Pitch, Range.GetLowerBoundValue(), Range.GetUpperBoundValue());
	Controller->SetControlRotation(NewRotation);
}

//プレイヤーカメラの左右方向の回転制限
void APlayerCharacter::ClampPlayerCameraYawRotation()
{
	//クランプが必要かどうか判定する
	const bool NeedClamp =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!NeedClamp)
		return;

	//視界の範囲は状態によって変わる
	const FFloatRange Range = [&]() -> FFloatRange {
		switch (CurrentActionMode)
		{
		case EPlayerActionMode::Move:
			//自由に動ける範囲
			return FFloatRange{-180.0f + DELTA, 180.0f - DELTA};
		case EPlayerActionMode::IsInLocker:
			return FFloatRange{LockerYawRotation + CameraYawWhenIsInLocker.GetLowerBoundValue(), LockerYawRotation + CameraYawWhenIsInLocker.GetUpperBoundValue()};
		default:
			return FFloatRange{0.0f, 0.0f};
		}
	}();

	//新しい角度を設定する
	FRotator NewRotation = Controller->GetControlRotation();
	NewRotation.Yaw = FMath::ClampAngle(NewRotation.Yaw, Range.GetLowerBoundValue(), Range.GetUpperBoundValue());
	Controller->SetControlRotation(NewRotation);
}

//死亡する
void APlayerCharacter::ToDie(AActor* Killer)
{
	//加害者がEnemyでなければならない
	AEnemy* Enemy = Cast<AEnemy>(Killer);
	if (!Enemy)
	{
		UE_LOG(LogTemp, Error, TEXT("Killer not equal Enemy!!"));
		return;
	}

	//死亡演出はそれ用の管理者に任せる
	APlayerDieEvent* DieEvent = Cast<APlayerDieEvent>(UGameplayStatics::GetActorOfClass(GetWorld(), APlayerDieEvent::StaticClass()));

	//ロッカーで死亡したかどうか
	//ロッカーに入るときも一緒に扱う
	const bool bIsInLocker = CurrentActionMode == EPlayerActionMode::IsInLocker || CurrentActionMode == EPlayerActionMode::GoingIntoLocker;
	if (bIsInLocker)
	{
		DieEvent->StartLockerDieEvent(this, Enemy, IsInLocker);
	}
	else
	{
		DieEvent->StartNormalDieEvent(this, Enemy);
	}

	//自分は死亡状態にしてこれから何もしないようにする
	CurrentActionMode = EPlayerActionMode::IsDying;
}

//入力コマンドを受け取る
void APlayerCharacter::InputedActionCommand()
{
	switch (CurrentActionMode)
	{
	case EPlayerActionMode::Move:
		DoActionNearObject();
		break;
	case EPlayerActionMode::IsInLocker:
		GetOutLocker();
		break;
	default:
		break;
	}
}

//近くにあるオブジェクトを作動させる
void APlayerCharacter::DoActionNearObject()
{
	ActionArea->DoAction();
	////条件を満たしたオブジェクトの中で一番近いオブジェクトを対象とし、アクションを実行する
	//TArray<AActor*> actors;
	//ActionArea->GetOverlappingActors(actors);

	////対象以外のオブジェクトを削除する
	//actors.RemoveAllSwap([](AActor* a) { return !a->GetClass()->ImplementsInterface(UActionable::StaticClass()); });

	//if (actors.Num() == 0)
	//	return;

	////対象との距離でソートし、一番近いオブジェクトを対象とする
	////NOTE:ソートアルゴリズムはクイックソートで、平均O(Nlog(N))より、対象オブジェクト数が少ないので全探索と同程度の速度になると予想しソートを使用
	////NOTE:ほんの少し、全探索より配列の再構築のオーバーヘッドがあるので改善の余地あり。
	//actors.Sort([this](auto& a, auto& b) {
	//	const FVector myLocation = GetActorLocation();
	//	return FVector::Dist2D(myLocation, a.GetActorLocation()) < FVector::Dist2D(myLocation, b.GetActorLocation());
	//});
	//IActionable::Execute_action(actors[0]);
}

//ロッカーから出る
void APlayerCharacter::GetOutLocker()
{
	//ロッカーが見つからない時は何もしない
	if (!IsInLocker)
	{
		UE_LOG(LogTemp, Error, TEXT("The Locker that Player is in is no exist!!"));
		return;
	}

	CurrentActionMode = EPlayerActionMode::GetOutOfLocker;
	IsInLocker->GetOutPlayer();
}

void APlayerCharacter::FixedLocationIfInLocker()
{
	if (CurrentActionMode == EPlayerActionMode::IsInLocker)
	{
		this->SetActorLocation(FixedLocation);
	}
}

//ロッカーの中に入る準備をする
void APlayerCharacter::IntoLockerReady()
{
	CurrentActionMode = EPlayerActionMode::GoingIntoLocker;
}

//ロッカーに入る
void APlayerCharacter::IntoLocker(ALocker* Locker, const FVector& Location, const FRotator& FrontRotator)
{
	IsInLocker = Locker;
	LockerYawRotation = FrontRotator.Yaw;
	Controller->SetControlRotation(FrontRotator);
	CurrentActionMode = EPlayerActionMode::IsInLocker;
	this->FixedLocation = Location;
}

void APlayerCharacter::LockerDoorOpenedEvent()
{
	FVector Location = GetActorLocation() + GetControlRotation().Vector() * 100.0f;
	SetActorLocation(Location);
	CurrentActionMode = EPlayerActionMode::Move;
}
