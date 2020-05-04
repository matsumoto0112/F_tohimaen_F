// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchManager.h"
#include "Invisible/ActionableObject/Actionable.h"
#include "Components/SphereComponent.h"
#include "Components/CapsuleComponent.h"

#include "Enemy.generated.h"

class ASoundObject;

UCLASS()
class INVISIBLE_API AEnemy : public AActor, public IActionable
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 移動処理
	void Moving(float DeltaTime);
	// 経路探索
	void SearchCourse(float DeltaTime);
	// プレイヤー探索
	void searchPlayer(AActor* OtherActor);
	// 待機時間設定
	void SetWait();
	// マテリアル
	void SetMaterial(float DeltaTime);
	// 透明化設定
	void AddReflection(float add);

	// 衝突開始時に呼ばれる
	UFUNCTION(BluePrintCallable, Category = "Collision")
	virtual void onComponentBeginOverlap(UPrimitiveComponent* HitComp, AActor* OtherActor,
	    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	//// 衝突中に呼ばれる
	//UFUNCTION(BluePrintCallable, Category = "Collision")
	//virtual void onComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor,
	//    UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& SweepResult);
    // 音が聞こえた
	void heardSound(ASoundObject* soundObject);
	// 歩行音の再生処理
	void playWalkSound(float deltaTime);
	// 水浴び
	UFUNCTION(BluePrintCallable, Category = "Collision")
	void bathing(AActor* OtherActor);
	UFUNCTION(BluePrintCallable, Category = "Collision")
	void overBathing();

private:

	// 移動速度
	UPROPERTY(EditAnywhere)
	float moveSpeed = 150.0f;
	// 回転速度
	UPROPERTY(EditAnywhere)
	float rotateSpeed = 15.0f;
	// 待機時間
	UPROPERTY(EditAnywhere)
	float waitTime = 3.0f;
	float waitTimer = 0.0f;
	// 濡れ判定
	UPROPERTY(EditAnywhere)
	float reflection = 1;
	// 渇き速度
	UPROPERTY(EditAnywhere)
	float thirstSpeed = 5.0f;

	//!< 歩いている時間(秒)
	float walkingSecond;

	// 経路管理クラス
	UPROPERTY(EditAnywhere)
	ASearchManager* searchManager;
	TArray<FVector> courses;

	public:
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	UCapsuleComponent* capsule;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Collision")
	USkeletalMeshComponent* skeltal;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "ActionArea")
	USphereComponent* actionableArea;
};
