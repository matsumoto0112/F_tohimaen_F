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
	GetCharacterMovement()->MaxWalkSpeed = WalkingMoveSpeed;

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

	if (CurrentActionMode == EPlayerActionMode::IsDying || CurrentActionMode == EPlayerActionMode::IsClear)
		return;

	//移動中なら歩行音を再生する
	if (CurrentActionMode == EPlayerActionMode::Move)
	{
		PlayWalkSound(DeltaTime);
	}

	//回転制限
	ClampPlayerCameraPitchRotation();
	ClampPlayerCameraYawRotation();

	//敵を検知
	//EnemyDetectArea->DetectAndWarn();
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
	PlayerInputComponent->BindAction("Sprint", EInputEvent::IE_Pressed, this, &APlayerCharacter::Sprint);
	PlayerInputComponent->BindAction("Sprint", EInputEvent::IE_Released, this, &APlayerCharacter::ReleaseSprint);
}

void APlayerCharacter::HeardEnemyWalkOnPuddleSound(AEnemy* enemy)
{
	enemy->ChangeStencilValueWhenWalkOnPuddle();
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
		MoveState = bInputtedSprint ? EPlayerMoveState::RUNNING : EPlayerMoveState::WALKING;
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
		MoveState = bInputtedSprint ? EPlayerMoveState::RUNNING : EPlayerMoveState::WALKING;
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

void APlayerCharacter::Sprint()
{
	SetSprintState(true);
}

void APlayerCharacter::ReleaseSprint()
{
	SetSprintState(false);
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
	if (!soundObject)
		return;

	//聞こえた音の種類によって場合分け
	switch (soundObject->getSoundType())
	{
	case ESoundType::Enemy_Walk_On_Puddle: {
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
	auto PlayWalkingSound = [&](float Intarval, ESoundType WalkSoundType) {
		WalkingSecond += DeltaTime;

		//歩いている時間が一定量を超えたら再生する
		if (WalkingSecond > Intarval)
		{
			WalkingSecond -= Intarval;

			//足元にレイを飛ばし、床がなんであるか判定する
			FHitResult hit;
			constexpr float LINE_LENGTH = 300.0f;
			const FVector Start = GetActorLocation();
			const FVector End = GetActorLocation() + FVector::DownVector * LINE_LENGTH;
			if (!GetWorld()->LineTraceSingleByChannel(hit, Start, End,
			        ECollisionChannel::ECC_Visibility, DetectFootObjectLinetraceQueryParams))
				return;
			const ESoundType sound = [&hit](ESoundType type) {
				//TODO:GamePlayTagで処理するのが望ましい
				//TODO:床と親クラスを一致させないと難しい
				if (hit.Actor->ActorHasTag(TEXT("Puddle")))
				{
					return ESoundType::Player_Walk_On_Puddle;
				}
				return type;
			}(WalkSoundType);

			const FVector SeLocation = [&]() {
				FVector location = GetActorLocation();
				location.Z = hit.Location.Z;
				return location;
			}();

			UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(sound, SeLocation, this);
		}
	};

	switch (MoveState)
	{
	case EPlayerMoveState::NO_MOVE:
		WalkingSecond = 0.0f;
		break;
	case EPlayerMoveState::WALKING:
		PlayWalkingSound(WalkingSoundPlayInterval, ESoundType::Player_Walk);
		break;
	case EPlayerMoveState::RUNNING:
		PlayWalkingSound(RunningSoundPlayInterval, ESoundType::Player_Running);
		break;
	default:
		break;
	}

	MoveState = EPlayerMoveState::NO_MOVE;
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
	const bool bIsInLocker = CurrentActionMode == EPlayerActionMode::IsInLocker;
	//自分は死亡状態にしてこれから何もしないようにする
	CurrentActionMode = EPlayerActionMode::IsDying;
	if (bIsInLocker)
	{
		DieEvent->StartLockerDieEvent(this, Enemy, IsInLocker);
	}
	else
	{
		DieEvent->StartNormalDieEvent(this, Enemy);
	}
}

void APlayerCharacter::SetCurrentActionMode(EPlayerActionMode Next)
{
	//死亡状態ならどの状態にも変化しない
	if (CurrentActionMode == EPlayerActionMode::IsDying)
		return;
	CurrentActionMode = Next;
}

//入力コマンドを受け取る
void APlayerCharacter::InputedActionCommand()
{
	switch (CurrentActionMode)
	{
	case EPlayerActionMode::Move:
	case EPlayerActionMode::IsInLocker:
		DoActionNearObject();
		break;
	default:
		break;
	}
}

//近くにあるオブジェクトを作動させる
void APlayerCharacter::DoActionNearObject()
{
	if (CurrentActionMode == EPlayerActionMode::IsDying ||
	    CurrentActionMode == EPlayerActionMode::GetOutOfLocker ||
	    CurrentActionMode == EPlayerActionMode::GoingIntoLocker ||
	    CurrentActionMode == EPlayerActionMode::IsClear)
		return;
	ActionArea->DoAction();
}

//ロッカー内にいるときに座標を固定させる
void APlayerCharacter::FixedLocationIfInLocker()
{
	if (CurrentActionMode == EPlayerActionMode::IsInLocker)
	{
		this->SetActorLocation(FixedLocation);
	}
}

void APlayerCharacter::SetSprintState(bool NextState)
{
	bInputtedSprint = NextState;
	GetCharacterMovement()->MaxWalkSpeed = bInputtedSprint ? RunningMoveSpeed : WalkingMoveSpeed;
}

//ロッカーの中に入る準備をする
void APlayerCharacter::IntoLockerReady(ALocker* Locker)
{
	IsInLocker = Locker;
	SetCurrentActionMode(EPlayerActionMode::GoingIntoLocker);
}

//ロッカーに入る
void APlayerCharacter::IntoLocker(const FVector& Location, const FRotator& FrontRotator)
{
	LockerYawRotation = FrontRotator.Yaw;
	Controller->SetControlRotation(FrontRotator);
	SetCurrentActionMode(EPlayerActionMode::IsInLocker);
	this->FixedLocation = Location;
}

//ロッカーのドアが開くイベント
void APlayerCharacter::LockerDoorOpenedEvent()
{
	FVector Location = GetActorLocation() + GetControlRotation().Vector() * OffsetLockerGetOutLength;
	SetActorLocation(Location);
	SetCurrentActionMode(EPlayerActionMode::Move);
}
