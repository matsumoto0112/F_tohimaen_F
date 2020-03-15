// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Engine.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//カメラを追加する
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	cameraComponent->SetupAttachment(GetCapsuleComponent());
	//ポーンがカメラの回転を制御できるように
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
}

//右方向への移動
void APlayerCharacter::moveRight(float value)
{
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(direction, value);
}

//カメラの横方向の回転処理
void APlayerCharacter::turn(float amount)
{
	const float yawValue = mouseSensitivity * amount * GetWorld()->GetDeltaSeconds();
	AddControllerYawInput(yawValue);
}

//カメラの上下方向の回転処理
void APlayerCharacter::lookup(float amount)
{
	const float pitchValue = mouseSensitivity * amount * GetWorld()->GetDeltaSeconds();
	AddControllerPitchInput(pitchValue);
}

//プレイヤーのアクションを実行する
void APlayerCharacter::playerAction()
{
	//条件を満たしたオブジェクトが存在したらその対象にアクションを実行する
	//レベル上に存在するオブジェクトすべてを動作させる
	TArray<AActor*> outActors;
	UGameplayStatics::GetAllActorsWithInterface(this->GetWorld(), UActionable::StaticClass(), outActors);

	for (AActor* actor : outActors)
	{
		IActionable::Execute_action(actor);
	}
}
