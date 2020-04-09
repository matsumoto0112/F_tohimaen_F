// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Engine/GameInstance.h"

#include "MyGameInstance.generated.h"

class USoundSystem;

/**
 *
 */
UCLASS()
class INVISIBLE_API UMyGameInstance : public UGameInstance
{
	GENERATED_BODY()
	UMyGameInstance();

public:
	static UMyGameInstance* GetInstance();
    virtual void Init() override;
    USoundSystem* getSoundSystem() const { return soundSystem; }
private:
	UPROPERTY(EditDefaultsOnly, Category = "Params")
	UDataTable* soundData;
	UPROPERTY(EditDefaultsOnly, Category = "Params")
	USoundAttenuation* attenuation;

private:
	USoundSystem* soundSystem;
};
