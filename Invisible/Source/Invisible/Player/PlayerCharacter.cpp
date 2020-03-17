// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Components/BoxComponent.h"
#include "Engine.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
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
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = maxMoveSpeed;
}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
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
}

//�E�����ւ̈ړ�
void APlayerCharacter::moveRight(float value)
{
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(direction, value);
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
    //NOTE:�\�[�g�A���S���Y���̓N�C�b�N�\�[�g��O(log(N))���A�ΏۃI�u�W�F�N�g�������Ȃ��̂őS�T���Ɠ����x�̑��x�ɂȂ�Ɨ\�z���\�[�g���g�p
    //NOTE:�ق�̏����A�S�T�����z��̍č\�z�̃I�[�o�[�w�b�h������̂ŉ��P�̗]�n����B
	actors.Sort([this](auto& a, auto& b) {
		const FVector myLocation = GetActorLocation();
		return FVector::Dist2D(myLocation, a.GetActorLocation()) < FVector::Dist2D(myLocation, b.GetActorLocation());
	});

	IActionable::Execute_action(actors[0]);
}
