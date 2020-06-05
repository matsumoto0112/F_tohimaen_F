// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Invisible/ActionableObject/Actionable.h"

#include "Locker.generated.h"

UENUM(BlueprintType)
enum class EDoorMode : uint8
{
	Default,
	Open,
	Close,
};

UCLASS()
class INVISIBLE_API ALocker : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALocker();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	/**
    * スプリンクラーを動作させる
    */
	virtual void action_Implementation() override;

	virtual EActionType GetActionType_Implementation() const override { return EActionType::Locker; }

	/**
    * プレイヤーを出す
    */
	void GetOutPlayer();
	/**
    * ドアを開ける
    */
	UFUNCTION(BlueprintCallable, Category = "Locker")
	void OpenDoor(float OpenSecond = 0.5f);

	/**
    * ドアを閉める
    */
	UFUNCTION(BlueprintCallable, Category = "Locker")
	void CloseDoor(float CloseSecond = 0.5f);
	/**
    * ロッカーのドアが開いているか
    */
	UFUNCTION(BlueprintCallable, Category = "Locker")
	bool IsOpenedDoor() const;

private:
	/**
    * ドアを回転させる
    */
	UFUNCTION()
	void RotateDoor(float Value);

protected:
	UPROPERTY(EditAnywhere)
	float DoorOpenAngle = 90.0f;

public:
	//!< ロッカーのボディメッシュ
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* BodyMeshComponent;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	USceneComponent* DummyDoor;
	//!< ロッカーのドアメッシュ
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UStaticMeshComponent* DoorMeshComponent;

	//!< プレイヤーの立つ場所
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
	UArrowComponent* PlayerStandPoint;

private:
	//!< 実行タスクリスト
	DECLARE_DELEGATE_RetVal(bool, FTask);
	TQueue<FTask> Tasks;
};
