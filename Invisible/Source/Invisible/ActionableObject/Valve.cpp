// Fill out your copyright notice in the Description page of Project Settings.

#include "Valve.h"

#include "Engine.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundSystem.h"
#include "Sprinkler.h"

// Sets default values
AValve::AValve()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = meshComponent;

	actionableArea = CreateDefaultSubobject<USphereComponent>(TEXT("ActionableArea"));
	actionableArea->InitSphereRadius(50.0f);
	actionableArea->SetCollisionProfileName("OverlapOnlyPawn");
	actionableArea->SetSimulatePhysics(false);
	actionableArea->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void AValve::BeginPlay()
{
	Super::BeginPlay();

	//�A�g���Ă���X�v�����N���[��T��
	TArray<AActor*> sprinklers;
	UGameplayStatics::GetAllActorsOfClass(this->GetWorld(), ASprinkler::StaticClass(), sprinklers);
	for (auto&& aSprinker : sprinklers)
	{
		ASprinkler* sprinkler = Cast<ASprinkler>(aSprinker);
		if (sprinkler->GetSprinklerID() == sprinklerID)
		{
			chainSprinklers.Add(sprinkler);
		}
	}
}

// Called every frame
void AValve::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//�X�v�����N���[�𓮍삳����
void AValve::action_Implementation()
{
	   //�Ή����邷�ׂẴX�v�����N���[���쓮������
	for (auto&& sp : chainSprinklers)
	{
		IActionable::Execute_action(sp);
	}

	//�o���u���Đ�
	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(ESoundType::Valve, GetActorLocation());
}
