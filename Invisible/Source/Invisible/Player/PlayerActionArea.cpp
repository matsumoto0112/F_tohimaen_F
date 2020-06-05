// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerActionArea.h"

#include "Engine.h"

UPlayerActionArea::UPlayerActionArea()
{
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
	PlayerHUD = Cast<APlayerHUD>(GetWorld()->GetFirstPlayerController()->MyHUD);
	if (PlayerHUD)
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, PlayerHUD->GetName());
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, TEXT("None"));
	}
}

void UPlayerActionArea::DoAction()
{
	if (NearlyObjects.Num() == 0)
		return;
	IActionable::Execute_action(NearlyObjects[0]);
}

void UPlayerActionArea::BeginOverlapEvent(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (!OtherActor->GetClass()->ImplementsInterface(UActionable::StaticClass()))
		return;
	NearlyObjects.Add(OtherActor);

	AActor* NearlyActor = nullptr;
	if (NearlyObjects.Num() > 1)
	{
		const FVector MyLocation = GetOwner()->GetActorLocation();
		NearlyObjects.Sort([MyLocation](auto& a, auto& b) {
			return FVector::Dist2D(MyLocation, a.GetActorLocation()) < FVector::Dist2D(MyLocation, b.GetActorLocation());
		});
	}
	NearlyActor = NearlyObjects[0];
	EActionType ActionType = IActionable::Execute_GetActionType(NearlyActor);
	PlayerHUD->SetCurrentNearlyObject(ActionType);
}

void UPlayerActionArea::EndOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (!OtherActor->GetClass()->ImplementsInterface(UActionable::StaticClass()))
		return;
	NearlyObjects.Remove(OtherActor);

	if (NearlyObjects.Num() == 0)
	{
		PlayerHUD->SetCurrentNearlyObject(EActionType::None);
		return;
	}

	AActor* NearlyActor = nullptr;
	if (NearlyObjects.Num() > 1)
	{
		const FVector MyLocation = GetOwner()->GetActorLocation();
		NearlyObjects.Sort([MyLocation](auto& a, auto& b) {
			return FVector::Dist2D(MyLocation, a.GetActorLocation()) < FVector::Dist2D(MyLocation, b.GetActorLocation());
		});
	}
	NearlyActor = NearlyObjects[0];
	EActionType ActionType = IActionable::Execute_GetActionType(NearlyActor);
	PlayerHUD->SetCurrentNearlyObject(ActionType);
}
