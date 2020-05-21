// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"

#include "Engine.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Invisible/ActionableObject/Locker.h"
#include "Invisible/Enemy/Enemy.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundObject.h"
#include "Invisible/System/SoundSystem.h"
#include "Invisible/System/StencilBitValue.h"
#include "Kismet/GameplayStatics.h"

//�R���X�g���N�^
APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	//�J������ǉ�����
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	CameraComponent->SetupAttachment(RootComponent);
	CameraComponent->SetRelativeLocation(FVector(30.0f, 0.0f, 80.0f));
	//�|�[�����J�����̉�]�𐧌�ł���悤��
	CameraComponent->bUsePawnControlRotation = true;

	//�A�N�V�������s�\�G���A���쐬
	ActionArea = CreateDefaultSubobject<UBoxComponent>(TEXT("ActionArea"));
	ActionArea->InitBoxExtent(FVector(32.0f, 32.0f, 64.0f));
	ActionArea->SetRelativeLocation(FVector(32.0f, 0.0f, 0.0f));
	ActionArea->SetSimulatePhysics(false);
	ActionArea->SetCollisionProfileName("OverlapAllDynamic");
	ActionArea->SetupAttachment(RootComponent);

	EnemyDetectArea = CreateDefaultSubobject<UEnemyDetectArea>(TEXT("EnemyDetectArea"));
	EnemyDetectArea->SetupAttachment(RootComponent);

	//�R���|�[�l���g�̏Փˎ��C�x���g��ǉ�
	this->GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::onComponentBeginOverlap);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	CurrentActionMode = EPlayerActionMode::Move;
	GetCharacterMovement()->MaxWalkSpeed = maxMoveSpeed;

	//�����ɔ�΂����C�̖������X�g
	param.AddIgnoredActor(this);
	//�G�̉��@�m�R���W�����Ɉ��������邱�Ƃ�����̂Œǉ����Ă���
	TArray<AActor*> enemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemy::StaticClass(), enemies);
	param.AddIgnoredActors(enemies);
}

void APlayerCharacter::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//�ړ����Ȃ���s�����Đ�����
	if (CurrentActionMode == EPlayerActionMode::Move)
	{
		playWalkSound(DeltaTime);
	}

	//��]����
	ClampPlayerCameraPitchRotation();
	ClampPlayerCameraYawRotation();

	//�G�����m
	EnemyDetectArea->DetectAndWarn();
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//���͂Ƀo�C���h������
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::moveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::lookup);
	PlayerInputComponent->BindAction("PlayerAction", EInputEvent::IE_Pressed, this, &APlayerCharacter::InputedActionCommand);
}

void APlayerCharacter::HeardEnemyWalkOnPuddleSound(AEnemy* enemy)
{
	//�G�������܂�𓥂񂾎��p�̃X�e���V���l��ݒ肷��
	auto SilhouetteSkeltal = enemy->GetSilhouetteSkeltal();
	const int32 Value = SilhouetteSkeltal->CustomDepthStencilValue | static_cast<int32>(EStencilBitValue::SilhouetteWhenEnemyWalkOnPuddle);
	SilhouetteSkeltal->SetCustomDepthStencilValue(Value);

	//��莞�Ԍ�ɃX�e���V���l�����ɖ߂�
	FTimerManager& TimerManager = GetWorldTimerManager();
	FTimerHandle Handle;
	TimerManager.SetTimer(Handle, [SilhouetteSkeltal]() {
		//�V�[���𒴂����Ƃ��ȂǃL���v�`���������ɂȂ�Ƃ��̑΍�
		if (!SilhouetteSkeltal)
			return;
		const int32 Value = SilhouetteSkeltal->CustomDepthStencilValue & ~static_cast<int32>(EStencilBitValue::SilhouetteWhenEnemyWalkOnPuddle);
		SilhouetteSkeltal->SetCustomDepthStencilValue(Value);
	},
	    EnemyVisibleTimeWhenEnemyWalkOnPuddle, false);
}

//�O�����ւ̈ړ�
void APlayerCharacter::moveForward(float value)
{
	if (CurrentActionMode != EPlayerActionMode::Move)
		return;
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(direction, value);

	//���l�ȏ�̈ړ��ʂ�����Ε����Ă���Ƃ݂Ȃ�
	if (std::abs(value) > WalkingThreshold)
	{
		bIsWalking = true;
	}
}

//�E�����ւ̈ړ�
void APlayerCharacter::moveRight(float value)
{
	if (CurrentActionMode != EPlayerActionMode::Move)
		return;
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(direction, value);

	//���l�ȏ�̈ړ��ʂ�����Ε����Ă���Ƃ݂Ȃ�
	if (std::abs(value) > WalkingThreshold)
	{
		bIsWalking = true;
	}
}

//�J�����̉������̉�]����
void APlayerCharacter::turn(float amount)
{
	const bool CanTurn =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!CanTurn)
		return;

	const float yawValue = RotateCoef * amount * GetWorld()->GetDeltaSeconds();
	AddControllerYawInput(yawValue);
}

//�J�����̏㉺�����̉�]����
void APlayerCharacter::lookup(float amount)
{
	const bool CanLookup =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!CanLookup)
		return;
	const float pitchValue = RotateCoef * amount * GetWorld()->GetDeltaSeconds();
	AddControllerPitchInput(pitchValue);
}

//�ՓˊJ�n���ɌĂ΂��
void APlayerCharacter::onComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//���I�u�W�F�N�g�Ȃ特����������͈͓��ɓ��������Ƃ�\��
	if (Cast<ASoundObject>(OtherActor))
	{
		heardSound(Cast<ASoundObject>(OtherActor));
		return;
	}
}

//������������͈͓��ɓ�����
void APlayerCharacter::heardSound(ASoundObject* soundObject)
{
	//�����������̎�ނɂ���ďꍇ����
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

void APlayerCharacter::playWalkSound(float deltaTime)
{
	//�����Ă���Ƃ��Ɉ�莞�Ԃ��Ƃɕ��s���Đ�
	if (bIsWalking)
	{
		//���̈ړ��̓��͂�����܂ŕ����Ă��Ȃ���ԂƂ��Ĉ���
		bIsWalking = false;

		WalkingSecond += deltaTime;

		//�����Ă��鎞�Ԃ����ʂ𒴂�����Đ�����
		if (WalkingSecond > WalkingSoundPlayInterval)
		{
			WalkingSecond -= WalkingSoundPlayInterval;

			FHitResult hit;

			if (!GetWorld()->LineTraceSingleByChannel(hit, GetActorLocation(), GetActorLocation() + FVector::DownVector * 1000.0f,
			        ECollisionChannel::ECC_Visibility, param))
				return;
			const ESoundType sound = [&hit]() {
				//TODO:GamePlayTag�ŏ�������̂��]�܂���
				//TODO:���Ɛe�N���X����v�����Ȃ��Ɠ��
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

//�v���C���[�J�����̏㉺�����̉�]����
void APlayerCharacter::ClampPlayerCameraPitchRotation()
{
	const bool NeedClamp =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!NeedClamp)
		return;

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

	FRotator NewRotation = Controller->GetControlRotation();
	NewRotation.Pitch = FMath::ClampAngle(NewRotation.Pitch, Range.GetLowerBoundValue(), Range.GetUpperBoundValue());
	Controller->SetControlRotation(NewRotation);
}

void APlayerCharacter::ClampPlayerCameraYawRotation()
{
	const bool NeedClamp =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!NeedClamp)
		return;

	const FFloatRange Range = [&]() -> FFloatRange {
		switch (CurrentActionMode)
		{
		case EPlayerActionMode::Move:
			return FFloatRange{-180.0f + DELTA, 180.0f - DELTA};
		case EPlayerActionMode::IsInLocker:
			return FFloatRange{LockerYawRotation + CameraYawWhenIsInLocker.GetLowerBoundValue(), LockerYawRotation + CameraYawWhenIsInLocker.GetUpperBoundValue()};
		default:
			return FFloatRange{0.0f, 0.0f};
		}
	}();
	FRotator NewRotation = Controller->GetControlRotation();
	NewRotation.Yaw = FMath::ClampAngle(NewRotation.Yaw, Range.GetLowerBoundValue(), Range.GetUpperBoundValue());
	Controller->SetControlRotation(NewRotation);
}

void APlayerCharacter::ToDie()
{
	CurrentActionMode = EPlayerActionMode::IsDying;
}

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

void APlayerCharacter::DoActionNearObject()
{
	//�����𖞂������I�u�W�F�N�g�̒��ň�ԋ߂��I�u�W�F�N�g��ΏۂƂ��A�A�N�V���������s����
	TArray<AActor*> actors;
	ActionArea->GetOverlappingActors(actors);

	//�ΏۈȊO�̃I�u�W�F�N�g���폜����
	actors.RemoveAllSwap([](AActor* a) { return !a->GetClass()->ImplementsInterface(UActionable::StaticClass()); });

	if (actors.Num() == 0)
		return;

	//�ΏۂƂ̋����Ń\�[�g���A��ԋ߂��I�u�W�F�N�g��ΏۂƂ���
	//NOTE:�\�[�g�A���S���Y���̓N�C�b�N�\�[�g�ŁA����O(Nlog(N))���A�ΏۃI�u�W�F�N�g�������Ȃ��̂őS�T���Ɠ����x�̑��x�ɂȂ�Ɨ\�z���\�[�g���g�p
	//NOTE:�ق�̏����A�S�T�����z��̍č\�z�̃I�[�o�[�w�b�h������̂ŉ��P�̗]�n����B
	actors.Sort([this](auto& a, auto& b) {
		const FVector myLocation = GetActorLocation();
		return FVector::Dist2D(myLocation, a.GetActorLocation()) < FVector::Dist2D(myLocation, b.GetActorLocation());
	});
	IActionable::Execute_action(actors[0]);
}

void APlayerCharacter::GetOutLocker()
{
	if (!IsInLocker)
	{
		return;
	}
	CurrentActionMode = EPlayerActionMode::GetOutOfLocker;
	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, [&]() {
		CurrentActionMode = EPlayerActionMode::Move;
	},
	    WaitTimeToGetOutLocker, false);
	IsInLocker->GetOutPlayer();
}

void APlayerCharacter::IntoLocker(ALocker* Locker, const FVector& Location, const FRotator& FrontRotator)
{
	CurrentActionMode = EPlayerActionMode::GoingIntoLocker;
	IsInLocker = Locker;
	LockerYawRotation = FrontRotator.Yaw;
	Controller->SetControlRotation(FrontRotator);
	this->SetActorLocation(Location);

	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, [&]() {
		CurrentActionMode = EPlayerActionMode::IsInLocker;
	},
	    WaitTimeToGoingIntoLocker, false);
}
