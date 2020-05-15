// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"

#include "Engine.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Invisible/Enemy/Enemy.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundObject.h"
#include "Invisible/System/SoundSystem.h"
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

	//アクション実行可能エリアを作成
	ActionArea = CreateDefaultSubobject<UBoxComponent>(TEXT("ActionArea"));
	ActionArea->InitBoxExtent(FVector(32.0f, 32.0f, 64.0f));
	ActionArea->SetRelativeLocation(FVector(32.0f, 0.0f, 0.0f));
	ActionArea->SetSimulatePhysics(false);
	ActionArea->SetCollisionProfileName("OverlapAllDynamic");
	ActionArea->SetupAttachment(RootComponent);

	EnemyDetectArea = CreateDefaultSubobject<UEnemyDetectArea>(TEXT("EnemyDetectArea"));
	EnemyDetectArea->SetupAttachment(RootComponent);

	//コンポーネントの衝突時イベントを追加
	this->GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::onComponentBeginOverlap);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = maxMoveSpeed;
	param.AddIgnoredActor(this);
	TArray<AActor*> enemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemy::StaticClass(), enemies);
	param.AddIgnoredActors(enemies);
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	playWalkSound(DeltaTime);
	clampPlayerCameraPitchRotation();

	EnemyDetectArea->DetectAndWarn();
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//入力にバインドさせる
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::moveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::lookup);
	PlayerInputComponent->BindAction("PlayerAction", EInputEvent::IE_Pressed, this, &APlayerCharacter::playerAction);
}

//前方向への移動
void APlayerCharacter::moveForward(float value)
{
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(direction, value);

	//一定値以上の移動量があれば歩いているとみなす
	if (std::abs(value) > WalkingThreshold)
	{
		bIsWalking = true;
	}
}

//右方向への移動
void APlayerCharacter::moveRight(float value)
{
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(direction, value);

	//一定値以上の移動量があれば歩いているとみなす
	if (std::abs(value) > WalkingThreshold)
	{
		bIsWalking = true;
	}
}

//カメラの横方向の回転処理
void APlayerCharacter::turn(float amount)
{
	const float yawValue = RotateCoef * amount * GetWorld()->GetDeltaSeconds();
	AddControllerYawInput(yawValue);
}

//カメラの上下方向の回転処理
void APlayerCharacter::lookup(float amount)
{
	const float pitchValue = RotateCoef * amount * GetWorld()->GetDeltaSeconds();
	AddControllerPitchInput(pitchValue);
}

//プレイヤーのアクションを実行する
void APlayerCharacter::playerAction()
{
	//条件を満たしたオブジェクトの中で一番近いオブジェクトを対象とし、アクションを実行する
	TArray<AActor*> actors;
	ActionArea->GetOverlappingActors(actors);

	//対象以外のオブジェクトを削除する
	actors.RemoveAllSwap([](AActor* a) { return !a->GetClass()->ImplementsInterface(UActionable::StaticClass()); });

	if (actors.Num() == 0)
		return;

	//対象との距離でソートし、一番近いオブジェクトを対象とする
	//NOTE:ソートアルゴリズムはクイックソートで、平均O(Nlog(N))より、対象オブジェクト数が少ないので全探索と同程度の速度になると予想しソートを使用
	//NOTE:ほんの少し、全探索より配列の再構築のオーバーヘッドがあるので改善の余地あり。
	actors.Sort([this](auto& a, auto& b) {
		const FVector myLocation = GetActorLocation();
		return FVector::Dist2D(myLocation, a.GetActorLocation()) < FVector::Dist2D(myLocation, b.GetActorLocation());
	});
	IActionable::Execute_action(actors[0]);
}

//衝突開始時に呼ばれる
void APlayerCharacter::onComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//音オブジェクトなら音が聞こえる範囲内に入ったことを表す
	if (Cast<ASoundObject>(OtherActor))
	{
		heardSound(Cast<ASoundObject>(OtherActor));
		return;
	}
}

//音が聞こえる範囲内に入った
void APlayerCharacter::heardSound(ASoundObject* soundObject)
{
	//聞こえた音の種類によって場合分け
	switch (soundObject->getSoundType())
	{
	case ESoundType::Valve:
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard valve sound"));
		break;
	case ESoundType::Sprinkler:
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard sprinkler sound"));
		break;
	case ESoundType::Player_Walk:
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard Player_Walk sound"));
		break;
	case ESoundType::Enemy_Walk:
		//heardEnemySound(soundObject->getSoundGenerateSource());
		break;
	case ESoundType::Player_Walk_On_Puddle:
		//GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard Player_Walk_On_Puddle sound"));
		break;
	case ESoundType::Enemy_Walk_On_Puddle:
		heardEnemySound(soundObject->getSoundGenerateSource());
		break;
	default:
		break;
	}
}

void APlayerCharacter::playWalkSound(float deltaTime)
{
	//歩いているときに一定時間ごとに歩行音再生
	if (bIsWalking)
	{
		//次の移動の入力があるまで歩いていない状態として扱う
		bIsWalking = false;

		WalkingSecond += deltaTime;

		//歩いている時間が一定量を超えたら再生する
		if (WalkingSecond > WalkingSoundPlayInterval)
		{
			WalkingSecond -= WalkingSoundPlayInterval;

			FHitResult hit;

			if (!GetWorld()->LineTraceSingleByChannel(hit, GetActorLocation(), GetActorLocation() + FVector::DownVector * 1000.0f,
			        ECollisionChannel::ECC_Visibility, param))
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

			const FVector seLocation = [&]() {
				FVector location = GetActorLocation();
				location.Z = hit.Location.Z;
				return location;
			}();

			UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(sound, seLocation, this);
		}
	}
	else
	{
		WalkingSecond = 0.0f;
	}
}

//プレイヤーカメラの上下方向の回転制限
void APlayerCharacter::clampPlayerCameraPitchRotation()
{
	FRotator rot = Controller->GetControlRotation();
	rot.Pitch = FMath::ClampAngle(rot.Pitch, MinCameraPitch, MaxCameraPitch);
	Controller->SetControlRotation(rot);
}

void APlayerCharacter::StartedGameEvent()
{
	if (Cast<APlayerController>(this->Controller))
	{
		this->DisableInput(Cast<APlayerController>(this->Controller));
	}
}
