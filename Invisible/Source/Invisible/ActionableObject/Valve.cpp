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
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetGenerateOverlapEvents(true);
	RootComponent = Mesh;
}

// Called when the game starts or when spawned
void AValve::BeginPlay()
{
	Super::BeginPlay();

	//�A�g���Ă���X�v�����N���[��T��
	TArray<AActor*> Sprinklers;
	UGameplayStatics::GetAllActorsOfClass(this->GetWorld(), ASprinkler::StaticClass(), Sprinklers);
	for (auto&& sp : Sprinklers)
	{
		ASprinkler* Sprinkler = Cast<ASprinkler>(sp);
		if (Sprinkler->GetSprinklerID() == SprinklerID)
		{
            ChainSprinklers.Add(Sprinkler);
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
	for (auto&& sp : ChainSprinklers)
	{
		IActionable::Execute_action(sp);
	}

	//�o���u���Đ�
	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(ESoundType::Valve, GetActorLocation(), this);
}
