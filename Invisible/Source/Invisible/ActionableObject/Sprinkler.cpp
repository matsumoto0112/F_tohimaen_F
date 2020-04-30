// Fill out your copyright notice in the Description page of Project Settings.

#include "Sprinkler.h"

#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundSystem.h"

namespace
{
	const FString path = "/Game/ActionableObject/Blueprint/Puddle_BP.Puddle_BP_C";
	static TSubclassOf<AActor> puddleOrigin;
}

//コンストラクタ
ASprinkler::ASprinkler()
{
	PrimaryActorTick.bCanEverTick = true;

	//メッシュコンポーネントを作成する
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = meshComponent;

	//パーティクルを作成する
	particleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));
	particleComponent->AttachToComponent(RootComponent,
	    FAttachmentTransformRules(
	        EAttachmentRule::KeepRelative,
	        EAttachmentRule::KeepRelative,
	        EAttachmentRule::KeepRelative,
	        false));

	wetArea = CreateDefaultSubobject<UBoxComponent>(TEXT("WetArea"));
    wetArea->InitBoxExtent(FVector(250.0f, 200.0f, 250.0f));
    wetArea->SetRelativeLocation(FVector(0.0f,-220.0f,0.0f));
	wetArea->SetGenerateOverlapEvents(false);
    wetArea->SetSimulatePhysics(false);
    wetArea->SetCollisionProfileName("OverlapAllDynamic");
	wetArea->SetupAttachment(RootComponent);

	//水たまりの元オブジェクトがまだ読み込めていなければ読み込む
	if (puddleOrigin == nullptr)
	{
		//NOTE:パスをコードにベタ打ちなので改善対象
		puddleOrigin = TSoftClassPtr<AActor>(FSoftObjectPath(*path)).LoadSynchronous();
	}
}

void ASprinkler::BeginPlay()
{
	Super::BeginPlay();
	puddleSpawned = false;

	//パーティクルをゲーム開始時に停止させる
	if (particleComponent)
	{
		particleComponent->SetEmitterEnable(particleEmitterName, false);
	}
}

void ASprinkler::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	//パーティクルの終了タイマーを消去する
	GetWorldTimerManager().ClearAllTimersForObject(this);
}

//アクションの実装
void ASprinkler::action_Implementation()
{
	particleComponent->SetEmitterEnable(particleEmitterName, true);
	wetArea->SetGenerateOverlapEvents(true);

	//タイマーが稼働中なら上書きする
	if (timerHandle.IsValid())
	{
		GetWorldTimerManager().ClearTimer(timerHandle);
	}
	//一定時間後にパーティクルを無効にする
	GetWorldTimerManager().SetTimer(timerHandle, [&]() {
		particleComponent->SetEmitterEnable(particleEmitterName, false);
		wetArea->SetGenerateOverlapEvents(false);
	},
	    activeTime, false);

	//スプリンクラーの音を再生する
	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(ESoundType::Sprinkler, GetActorLocation(), this);

	//水たまりの元がなければ何もしない
	if (puddleOrigin == nullptr)
		return;
	//水たまりがすでにあるなら何もしない
	if (puddleSpawned)
		return;
	//水たまりの発生ポイントすべてに水たまりを配置する
	for (auto& point : puddlePoints)
	{
		AActor* a = GetWorld()->SpawnActor<AActor>(puddleOrigin);
		a->SetActorLocation(point->GetActorLocation());
	}
	puddleSpawned = true;
}

void ASprinkler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
