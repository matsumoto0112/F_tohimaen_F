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
	this->GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::OnComponentBeginOverlap);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	CurrentActionMode = EPlayerActionMode::Move;
	GetCharacterMovement()->MaxWalkSpeed = MaxMoveSpeed;

	//�����ɔ�΂����C�̖������X�g
	DetectFootObjectLinetraceQueryParams.AddIgnoredActor(this);
	//�G�̉��@�m�R���W�����Ɉ��������邱�Ƃ�����̂Œǉ����Ă���
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

	//�ړ����Ȃ���s�����Đ�����
	if (CurrentActionMode == EPlayerActionMode::Move)
	{
		PlayWalkSound(DeltaTime);
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
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::Lookup);
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
void APlayerCharacter::MoveForward(float Value)
{
	if (CurrentActionMode != EPlayerActionMode::Move)
		return;
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(direction, Value);

	//���l�ȏ�̈ړ��ʂ�����Ε����Ă���Ƃ݂Ȃ�
	if (std::abs(Value) > WalkingThreshold)
	{
		bIsWalking = true;
	}
}

//�E�����ւ̈ړ�
void APlayerCharacter::MoveRight(float Value)
{
	if (CurrentActionMode != EPlayerActionMode::Move)
		return;
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(direction, Value);

	//���l�ȏ�̈ړ��ʂ�����Ε����Ă���Ƃ݂Ȃ�
	if (std::abs(Value) > WalkingThreshold)
	{
		bIsWalking = true;
	}
}

//�J�����̉������̉�]����
void APlayerCharacter::Turn(float Amount)
{
	const bool CanTurn =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!CanTurn)
		return;

	const float YawValue = RotateCoef * Amount * GetWorld()->GetDeltaSeconds();
	AddControllerYawInput(YawValue);
}

//�J�����̏㉺�����̉�]����
void APlayerCharacter::Lookup(float Amount)
{
	const bool CanLookup =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!CanLookup)
		return;
	const float PitchValue = RotateCoef * Amount * GetWorld()->GetDeltaSeconds();
	AddControllerPitchInput(PitchValue);
}

//�ՓˊJ�n���ɌĂ΂��
void APlayerCharacter::OnComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//���I�u�W�F�N�g�Ȃ特����������͈͓��ɓ��������Ƃ�\��
	if (Cast<ASoundObject>(OtherActor))
	{
		HeardSound(Cast<ASoundObject>(OtherActor));
		return;
	}
}

//������������͈͓��ɓ�����
void APlayerCharacter::HeardSound(ASoundObject* soundObject)
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

void APlayerCharacter::PlayWalkSound(float DeltaTime)
{
	//�����Ă���Ƃ��Ɉ�莞�Ԃ��Ƃɕ��s���Đ�
	if (bIsWalking)
	{
		//���̈ړ��̓��͂�����܂ŕ����Ă��Ȃ���ԂƂ��Ĉ���
		bIsWalking = false;

		WalkingSecond += DeltaTime;

		//�����Ă��鎞�Ԃ����ʂ𒴂�����Đ�����
		if (WalkingSecond > WalkingSoundPlayInterval)
		{
			WalkingSecond -= WalkingSoundPlayInterval;

            //�����Ƀ��C���΂��A�����Ȃ�ł��邩���肷��
			FHitResult hit;
			constexpr float LINE_LENGTH = 300.0f;
			const FVector Start = GetActorLocation();
			const FVector End = GetActorLocation() + FVector::DownVector * LINE_LENGTH;
			if (!GetWorld()->LineTraceSingleByChannel(hit, Start, End,
			        ECollisionChannel::ECC_Visibility, DetectFootObjectLinetraceQueryParams))
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

//�v���C���[�J�����̏㉺�����̉�]����
void APlayerCharacter::ClampPlayerCameraPitchRotation()
{
	//�N�����v���K�v���ǂ������肷��
	const bool NeedClamp =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!NeedClamp)
		return;

	//���E�͈̔͂͏�Ԃɂ���ĕς��
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

	//�V�����p�x��ݒ肷��
	FRotator NewRotation = Controller->GetControlRotation();
	NewRotation.Pitch = FMath::ClampAngle(NewRotation.Pitch, Range.GetLowerBoundValue(), Range.GetUpperBoundValue());
	Controller->SetControlRotation(NewRotation);
}

//�v���C���[�J�����̍��E�����̉�]����
void APlayerCharacter::ClampPlayerCameraYawRotation()
{
	//�N�����v���K�v���ǂ������肷��
	const bool NeedClamp =
	    (CurrentActionMode == EPlayerActionMode::Move) || (CurrentActionMode == EPlayerActionMode::IsInLocker);
	if (!NeedClamp)
		return;

	//���E�͈̔͂͏�Ԃɂ���ĕς��
	const FFloatRange Range = [&]() -> FFloatRange {
		switch (CurrentActionMode)
		{
		case EPlayerActionMode::Move:
            //���R�ɓ�����͈�
			return FFloatRange{-180.0f + DELTA, 180.0f - DELTA};
		case EPlayerActionMode::IsInLocker:
			return FFloatRange{LockerYawRotation + CameraYawWhenIsInLocker.GetLowerBoundValue(), LockerYawRotation + CameraYawWhenIsInLocker.GetUpperBoundValue()};
		default:
			return FFloatRange{0.0f, 0.0f};
		}
	}();

	//�V�����p�x��ݒ肷��
	FRotator NewRotation = Controller->GetControlRotation();
	NewRotation.Yaw = FMath::ClampAngle(NewRotation.Yaw, Range.GetLowerBoundValue(), Range.GetUpperBoundValue());
	Controller->SetControlRotation(NewRotation);
}

//���S����
void APlayerCharacter::ToDie(AActor* Killer)
{
	//���[�h��ύX����ɂƂǂ߂�
	//���Ƃ�BP�ŏ�������
	CurrentActionMode = EPlayerActionMode::IsDying;
}

//���̓R�}���h���󂯎��
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

//�߂��ɂ���I�u�W�F�N�g���쓮������
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

//���b�J�[����o��
void APlayerCharacter::GetOutLocker()
{
	//���b�J�[��������Ȃ����͉������Ȃ�
	if (!IsInLocker)
	{
		UE_LOG(LogTemp, Error, TEXT("The Locker that Player is in is no exist!!"));
		return;
	}

	CurrentActionMode = EPlayerActionMode::GetOutOfLocker;

    //�����̑ҋ@���Ԃ̂̂�������悤�ɂȂ�
	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, [&]() {
        FVector Location = GetActorLocation() + GetControlRotation().Vector() * 50.0f;
        SetActorLocation(Location);
		CurrentActionMode = EPlayerActionMode::Move;
	},
	    WaitTimeToGetOutLocker, false);
	IsInLocker->GetOutPlayer();
}

//���b�J�[�ɓ���
void APlayerCharacter::IntoLocker(ALocker* Locker, const FVector& Location, const FRotator& FrontRotator)
{
	CurrentActionMode = EPlayerActionMode::GoingIntoLocker;

	IsInLocker = Locker;
	LockerYawRotation = FrontRotator.Yaw;
	Controller->SetControlRotation(FrontRotator);
	this->SetActorLocation(Location);

	//�����̑ҋ@���Ԃ̂̂���𓮂�����悤�ɂȂ�
	FTimerHandle handle;
	GetWorldTimerManager().SetTimer(handle, [&]() {
		CurrentActionMode = EPlayerActionMode::IsInLocker;
	},
	    WaitTimeToGoingIntoLocker, false);
}
