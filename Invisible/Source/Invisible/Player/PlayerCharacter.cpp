// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"

#include "Engine.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Invisible/Enemy/Enemy.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundObject.h"
#include "Invisible/System/SoundSystem.h"
#include "Kismet/GameplayStatics.h"

//�R���X�g���N�^
APlayerCharacter::APlayerCharacter()
{
	PrimaryActorTick.bCanEverTick = true;

	//�J������ǉ�����
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	cameraComponent->SetupAttachment(GetCapsuleComponent());
	cameraComponent->SetRelativeLocation(FVector(30.0f, 0.0f, 80.0f));
	//�|�[�����J�����̉�]�𐧌�ł���悤��
	cameraComponent->bUsePawnControlRotation = true;

	//�A�N�V�������s�\�G���A���쐬
	actionArea = CreateDefaultSubobject<UBoxComponent>(TEXT("ActionArea"));
	actionArea->InitBoxExtent(FVector(32.0f, 32.0f, 64.0f));
	actionArea->SetRelativeLocation(FVector(32.0f, 0.0f, 0.0f));
	actionArea->SetSimulatePhysics(false);
	actionArea->SetCollisionProfileName("OverlapAllDynamic");
	actionArea->SetupAttachment(GetCapsuleComponent());

	//�R���|�[�l���g�̏Փˎ��C�x���g��ǉ�
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
}

void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//���͂Ƀo�C���h������
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::moveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::moveRight);
	PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::turn);
	PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::lookup);
	PlayerInputComponent->BindAction("PlayerAction", EInputEvent::IE_Pressed, this, &APlayerCharacter::playerAction);
}

//�O�����ւ̈ړ�
void APlayerCharacter::moveForward(float value)
{
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(direction, value);

	//���l�ȏ�̈ړ��ʂ�����Ε����Ă���Ƃ݂Ȃ�
	if (std::abs(value) > walkingThreshold)
	{
		isWalking = true;
	}
}

//�E�����ւ̈ړ�
void APlayerCharacter::moveRight(float value)
{
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(direction, value);

	//���l�ȏ�̈ړ��ʂ�����Ε����Ă���Ƃ݂Ȃ�
	if (std::abs(value) > walkingThreshold)
	{
		isWalking = true;
	}
}

//�J�����̉������̉�]����
void APlayerCharacter::turn(float amount)
{
	const float yawValue = mouseSensitivity * amount * GetWorld()->GetDeltaSeconds();
	AddControllerYawInput(yawValue);
}

//�J�����̏㉺�����̉�]����
void APlayerCharacter::lookup(float amount)
{
	const float pitchValue = mouseSensitivity * amount * GetWorld()->GetDeltaSeconds();
	AddControllerPitchInput(pitchValue);
}

//�v���C���[�̃A�N�V���������s����
void APlayerCharacter::playerAction()
{
	//�����𖞂������I�u�W�F�N�g�̒��ň�ԋ߂��I�u�W�F�N�g��ΏۂƂ��A�A�N�V���������s����
	TArray<AActor*> actors;
	actionArea->GetOverlappingActors(actors);

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
	//�����Ă���Ƃ��Ɉ�莞�Ԃ��Ƃɕ��s���Đ�
	if (isWalking)
	{
		//���̈ړ��̓��͂�����܂ŕ����Ă��Ȃ���ԂƂ��Ĉ���
		isWalking = false;

		walkingSecond += deltaTime;

		//�����Ă��鎞�Ԃ����ʂ𒴂�����Đ�����
		if (walkingSecond > walkingSoundPlayInterval)
		{
			walkingSecond -= walkingSoundPlayInterval;

			FHitResult hit;

			if (!GetWorld()->LineTraceSingleByChannel(hit, GetActorLocation(), GetActorLocation() + FVector::DownVector * 1000.0f,
			        ECollisionChannel::ECC_Visibility, param))
				return;
			UKismetSystemLibrary::DrawDebugLine(GetWorld(), GetActorLocation(), GetActorLocation() + FVector::DownVector * 1000.0f, FLinearColor::Blue, 20.0f);

			UE_LOG(LogTemp, Log, TEXT("%s"), *hit.Actor->GetName());
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
		walkingSecond = 0.0f;
	}
}

//�v���C���[�J�����̏㉺�����̉�]����
void APlayerCharacter::clampPlayerCameraPitchRotation()
{
	FRotator rot = Controller->GetControlRotation();
	rot.Pitch = FMath::ClampAngle(rot.Pitch, minCameraPitch, maxCameraPitch);
	Controller->SetControlRotation(rot);
}
