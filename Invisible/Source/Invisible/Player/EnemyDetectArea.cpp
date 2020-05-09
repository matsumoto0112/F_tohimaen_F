// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyDetectArea.h"

#include "Engine.h"
#include "Kismet/GameplayStatics.h"

//コンストラクタ
UEnemyDetectArea::UEnemyDetectArea()
{
	SphereRadius = 1000.0f;

	this->OnComponentBeginOverlap.AddDynamic(this, &UEnemyDetectArea::BeginOverlapEvent);
	this->OnComponentEndOverlap.AddDynamic(this, &UEnemyDetectArea::EndOverlapEvent);
}

void UEnemyDetectArea::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

//検知と警告
void UEnemyDetectArea::DetectAndWarn()
{
	const FVector Location = GetComponentLocation();
	for (auto&& Enemy : Enemies)
	{
		//すでに警告していたら何もしない
		if (Enemy.bWarned)
			continue;

		//レイを飛ばして間に障害物がないか調べる
		//NOTE:マップの構造上今いるモジュールからレイを飛ばしても衝突しないため、角に立っているときなど間に壁がある場合でも基本的に壁は判定をとれない
		//でもそのほうが薄壁の先に敵がいても検知できるので都合がよく、そのままにしている
		const FVector EnemyLocation = Enemy.Enemy->GetActorLocation();
		FHitResult Result;
		if (GetWorld()->LineTraceSingleByChannel(Result, Location, EnemyLocation, ECollisionChannel::ECC_Visibility))
		{
			//間に障害物がなければ警告を発する
			if (Result.Actor == Enemy.Enemy)
			{
				APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
				DynamicForceFeedbackHandle = PlayerController->PlayDynamicForceFeedback(1.0f, Duration, true, true, true, true,
				    EDynamicForceFeedbackAction::Start, DynamicForceFeedbackHandle);
				Enemy.bWarned = true;
			}
		}
	}
}

//何かとオーバーラップした
void UEnemyDetectArea::BeginOverlapEvent(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (CheckOverlappingsActorIsEnemy(OtherActor, OtherComp))
    {
        BeginOverlapEnemy(Cast<AEnemy>(OtherActor));
    }
}

//何かとオーバーラップを解除した
void UEnemyDetectArea::EndOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (CheckOverlappingsActorIsEnemy(OtherActor,OtherComp))
    {
        EndOverlapEnemy(Cast<AEnemy>(OtherActor));
    }
}

//アクターが敵かどうか判定する
bool UEnemyDetectArea::CheckOverlappingsActorIsEnemy(AActor* OtherActor, UPrimitiveComponent* OtherComp)
{
	AEnemy* Enemy = Cast<AEnemy>(OtherActor);
    //敵のプレイヤー検知範囲をとることが多く、その場合、壁越しでも取ることが多いので敵のモデルを取得して判定している
    USkeletalMeshComponent* Skeltal = Cast<USkeletalMeshComponent>(OtherComp);
	return Enemy && Skeltal;
}

//敵とオーバーラップした
void UEnemyDetectArea::BeginOverlapEnemy(AEnemy* Enemy)
{
    //敵リストに追加する
	Enemies.Add({Enemy, false});
}

//敵とオーバーラップ解除した
void UEnemyDetectArea::EndOverlapEnemy(AEnemy* Enemy)
{
    //敵リストから外す
	Enemies.RemoveAll([Enemy](FEnemyDetect& detect) { return detect.Enemy == Enemy; });
}
