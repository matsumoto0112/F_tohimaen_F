// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Engine.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//�J������ǉ�����
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	cameraComponent->SetupAttachment(GetCapsuleComponent());
	//�|�[�����J�����̉�]�𐧌�ł���悤��
	cameraComponent->bUsePawnControlRotation = true;
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
