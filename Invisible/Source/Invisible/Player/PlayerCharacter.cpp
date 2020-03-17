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

	//カメラを追加する
	cameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FPSCamera"));
	cameraComponent->SetupAttachment(GetCapsuleComponent());
	cameraComponent->SetRelativeLocation(FVector(30.0f, 0.0f, 80.0f));
	//ポーンがカメラの回転を制御できるように
	cameraComponent->bUsePawnControlRotation = true;

    //アクション実行可能エリアを作成
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
	//条件を満たしたオブジェクトの中で一番近いオブジェクトを対象とし、アクションを実行する
	TArray<AActor*> actors;
	actionArea->GetOverlappingActors(actors);

    //対象以外のオブジェクトを削除する
	actors.RemoveAllSwap([](AActor* a) { return !a->GetClass()->ImplementsInterface(UActionable::StaticClass()); });

	if (actors.Num() == 0)
		return;

    //対象との距離でソートし、一番近いオブジェクトを対象とする
    //NOTE:ソートアルゴリズムはクイックソートでO(log(N))より、対象オブジェクト数が少ないので全探索と同程度の速度になると予想しソートを使用
    //NOTE:ほんの少し、全探索より配列の再構築のオーバーヘッドがあるので改善の余地あり。
	actors.Sort([this](auto& a, auto& b) {
		const FVector myLocation = GetActorLocation();
		return FVector::Dist2D(myLocation, a.GetActorLocation()) < FVector::Dist2D(myLocation, b.GetActorLocation());
	});

	IActionable::Execute_action(actors[0]);
}
