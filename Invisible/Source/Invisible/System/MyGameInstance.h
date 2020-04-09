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
    virtual void Init() override;

    UFUNCTION()
	static UMyGameInstance* GetInstance();
    UFUNCTION()
    USoundSystem* getSoundSystem() const { return soundSystem; }
private:
	UPROPERTY(EditDefaultsOnly, Category = "Params")
	UDataTable* soundData;

private:
	USoundSystem* soundSystem;
};
