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

//�A�N�V���������s����
void UPlayerActionArea::DoAction()
{
	if (NearlyObjects.Num() == 0)
		return;

	//�������Ƀ\�[�g����Ă���͂��Ȃ̂ŁA��ԋ߂����̂����s����
	IActionable::Execute_action(NearlyObjects[0]);
}

//���t���[���X�V
void UPlayerActionArea::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	//�߂��ɂ���I�u�W�F�N�g����A�N�V�����̎�ނ��擾����
	//�߂��ɃI�u�W�F�N�g���Ȃ����None�ɂ���
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
	//�A�N�V�����\�ł���΋߂��̃I�u�W�F�N�g���X�g�ɒǉ�����
	if (!OtherActor->GetClass()->ImplementsInterface(UActionable::StaticClass()))
		return;
	NearlyObjects.Add(OtherActor);

	//�������Ń\�[�g���A�߂��ɂ�����̂��Ƃ�₷������
	SortByDistance();
}

void UPlayerActionArea::EndOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	//�A�N�V�����\�I�u�W�F�N�g�ł���΃��X�g����폜����
	if (!OtherActor->GetClass()->ImplementsInterface(UActionable::StaticClass()))
		return;
	NearlyObjects.Remove(OtherActor);

	//�폜�������Ƃɂ���ċ������̍X�V������K�v������
	SortByDistance();
}

void UPlayerActionArea::SortByDistance()
{
	const FVector MyLocation = GetOwner()->GetActorLocation();
	NearlyObjects.Sort([MyLocation](auto& a, auto& b) {
		return FVector::Dist2D(MyLocation, a.GetActorLocation()) < FVector::Dist2D(MyLocation, b.GetActorLocation());
	});
}
