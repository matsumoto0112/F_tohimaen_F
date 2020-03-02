// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Engine.h"
#include "Camera/CameraComponent.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    //カメラを追加する
    mCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
    mCameraComponent->SetupAttachment(GetCapsuleComponent());
    //ポーンがカメラの回転を制御できるように
    mCameraComponent->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
    Super::BeginPlay();
    GetCharacterMovement()->MaxWalkSpeed = mMaxMoveSpeed;

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

    //入力にバインドさせる
    PlayerInputComponent->BindAxis("MoveForward", this, &APlayerCharacter::moveForward);
    PlayerInputComponent->BindAxis("MoveRight", this, &APlayerCharacter::moveRight);
    PlayerInputComponent->BindAxis("Turn", this, &APlayerCharacter::turn);
    PlayerInputComponent->BindAxis("LookUp", this, &APlayerCharacter::lookup);
}

//前方向への移動
void APlayerCharacter::moveForward(float value)
{
    FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
    AddMovementInput(direction, value);
}

//右方向への移動
void APlayerCharacter::moveRight(float value)
{
    FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
    AddMovementInput(direction, value);
}

//カメラの横方向の回転処理
void APlayerCharacter::turn(float amount)
{
    const float yawValue = mMouseSensitivity * amount * GetWorld()->GetDeltaSeconds();
    AddControllerYawInput(yawValue);
}

//カメラの上下方向の回転処理
void APlayerCharacter::lookup(float amount)
{
    const float pitchValue = mMouseSensitivity * amount * GetWorld()->GetDeltaSeconds();
    AddControllerPitchInput(pitchValue);
}

