// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerCharacter.h"

#include "Engine.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundObject.h"
#include "Invisible/System/SoundSystem.h"
#include "Kismet/GameplayStatics.h"

namespace
{
    constexpr float WALKING_THRESHOLD = 0.5f; //!< 歩いているとみなす閾値
    constexpr float WALKING_SOUND_PLAY_INTERVAL = 0.66f; //!< 歩行音の再生間隔
}

//コンストラクタ
APlayerCharacter::APlayerCharacter()
{
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

	//コンポーネントの衝突時イベントを追加
	this->GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &APlayerCharacter::onComponentBeginOverlap);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	GetCharacterMovement()->MaxWalkSpeed = maxMoveSpeed;
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    //歩いているときに一定時間ごとに歩行音再生
	if (isWalking)
	{
		walkingSecond += DeltaTime;
		if (walkingSecond > WALKING_SOUND_PLAY_INTERVAL)
		{
            walkingSecond -= WALKING_SOUND_PLAY_INTERVAL;
			FVector location = GetActorLocation();

            //TODO:床を取得して高さを取得するか、アニメーションにサウンドの再生を任せるかのどちらかにする
			location.Z = 50.0f;
			UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(ESoundType::Player_Walk, location);
		}
	}
	else
	{
        isWalking = 0.0f;
	}
    isWalking = false;
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
    if (std::abs(value) > WALKING_THRESHOLD)
    {
        isWalking = true;
    }
}

//右方向への移動
void APlayerCharacter::moveRight(float value)
{
	const FVector direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(direction, value);

    //一定値以上の移動量があれば歩いているとみなす
	if (std::abs(value) > WALKING_THRESHOLD)
	{
        isWalking = true;
	}
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
	switch (soundObject->getSoundType())
	{
		//バルブの音が聞こえた
	case ESoundType::Valve:
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard valve sound"));
		break;
		//スプリンクラーの音が聞こえた
	case ESoundType::Sprinkler:
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard sprinkler sound"));
		break;
	case ESoundType::Player_Walk:
		GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Red, TEXT("heard Player_Walk sound"));
		break;
	default:
		break;
	}
}
