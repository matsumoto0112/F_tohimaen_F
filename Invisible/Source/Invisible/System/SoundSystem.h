// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/AudioComponent.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "Engine/DataTable.h"
#include "GameFramework/Actor.h"

#include "SoundSystem.generated.h"

class USoundAttenuation;

UENUM(BlueprintType)
enum class ESoundType : uint8
{
	Valve,
	Sprinkler,
	Player_Walk,
	Enemy_Walk,
	Walk_On_Puddle,
};

USTRUCT(BlueprintType)
struct INVISIBLE_API FSoundData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere)
	ESoundType soundType;
	UPROPERTY(EditAnywhere)
	USoundBase* sound;
};

UCLASS()
class INVISIBLE_API ASoundSystem : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASoundSystem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	TSubclassOf<AActor> soundObjectOrigin;
	UPROPERTY(EditDefaultsOnly)
	USoundAttenuation* soundAttenuation;
	UPROPERTY(EditAnywhere)
	UDataTable* dataTable;
};
