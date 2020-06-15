// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerActionArea.h"

#include "Engine.h"

UPlayerActionArea::UPlayerActionArea()
{
	PrimaryComponentTick.bCanEverTick = true;
	InitBoxExtent(FVector(32.0f, 32.0f, 64.0f));
	SetRelativeLocation(FVector(64.0f, 0.0f, 0.0f));
	SetSimulatePhysics(false);
	SetCollisionProfileName("PlayerActionArea");

	this->OnComponentBeginOverlap.AddDynamic(this, &UPlayerActionArea::BeginOverlapEvent);
	this->OnComponentEndOverlap.AddDynamic(this, &UPlayerActionArea::EndOverlapEvent);
}

void UPlayerActionArea::BeginPlay()
{
	Super::BeginPlay();
	FWorldContext* context = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport);
	this->PlayerHUD = Cast<APlayerHUD>(GetWorld()->GetFirstPlayerController()->MyHUD);
}

//アクションを実行する
void UPlayerActionArea::DoAction()
{
	if (NearlyObjects.Num() == 0)
		return;

	//距離順にソートされているはずなので、一番近いものを実行する
	IActionable::Execute_action(NearlyObjects[0]);
}

//毎フレーム更新
void UPlayerActionArea::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//近くにあるオブジェクトからアクションの種類を取得する
	//近くにオブジェクトがなければNoneにする
	const EActionType ActionType = [&]() {
		if (NearlyObjects.Num() == 0)
		{
			return EActionType::None;
		}
		return IActionable::Execute_GetActionType(NearlyObjects[0]);
	}();
	PlayerHUD->SetCurrentNearlyObject(ActionType);
}

void UPlayerActionArea::BeginOverlapEvent(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//アクション可能であれば近くのオブジェクトリストに追加する
	if (!OtherActor->GetClass()->ImplementsInterface(UActionable::StaticClass()))
		return;
	NearlyObjects.Add(OtherActor);

	//距離順でソートし、近くにあるものをとりやすくする
	SortByDistance();
}

void UPlayerActionArea::EndOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//アクション可能オブジェクトであればリストから削除する
	if (!OtherActor->GetClass()->ImplementsInterface(UActionable::StaticClass()))
		return;
	NearlyObjects.Remove(OtherActor);

	//削除したことによって距離順の更新をする必要がある
	SortByDistance();
}

void UPlayerActionArea::SortByDistance()
{
	const FVector MyLocation = GetOwner()->GetActorLocation();
	NearlyObjects.Sort([MyLocation](auto& a, auto& b) {
		return FVector::Dist2D(MyLocation, a.GetActorLocation()) < FVector::Dist2D(MyLocation, b.GetActorLocation());
	});
}
