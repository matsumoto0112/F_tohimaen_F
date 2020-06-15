// Fill out your copyright notice in the Description page of Project Settings.

#include "PlayerDieEvent.h"

#include "Invisible/ActionableObject/Locker.h"
#include "Invisible/Enemy/Enemy.h"
#include "Invisible/Player/PlayerCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
APlayerDieEvent::APlayerDieEvent()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APlayerDieEvent::BeginPlay()
{
	Super::BeginPlay();
	bIsStartedEvent = false;
	TaskManager.Clear();
}

// Called every frame
void APlayerDieEvent::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	TaskManager.Update();
}

void APlayerDieEvent::InitPostProcess()
{
	SetPostProcessParametersWithDelay();
}

void APlayerDieEvent::StartNormalDieEvent(APlayerCharacter* Player, AEnemy* Enemy)
{
	auto MakeTimer = [&](float Time) {
		return [&, time = Time]() mutable {
			time -= GetWorld()->GetDeltaSeconds();
			return time;
		};
	};

	if (bIsStartedEvent)
		return;
	this->bIsStartedEvent = true;
	InitPostProcess();

	//�ʏ펀�S�C�x���g�̃v���C���[���̗���
	//1.�G�̂ق������X�Ɍ���
	{
		const FVector PlayerLocation = Player->GetActorLocation();
		const FVector EnemyLocation = Enemy->GetActorLocation() + FVector(0.0f, 0.0f, -50.0f);
		const FRotator TargetRotation = UKismetMathLibrary::FindLookAtRotation(PlayerLocation, EnemyLocation);

		QueueTaskManager::FTask Task;
		Task.BindLambda([&, Player, TargetRotation]() {
			const float DeltaTime = GetWorld()->GetDeltaSeconds();
			const FRotator Rotation = FMath::RInterpTo(Player->GetControlRotation(), TargetRotation, DeltaTime, 3.0f);
			Player->Controller->SetControlRotation(Rotation);
			return TargetRotation.Equals(Player->GetControlRotation(), 1.0f);
		});
		TaskManager.AddTask(Task);
	}
	//2.�G�̃A�j���[�V�����ҋ@
	{
		QueueTaskManager::FTask Task;
		Task.BindLambda([&, Timer = MakeTimer(WaitTime)]() mutable {
			return Timer() <= 0.0f;
		});
		TaskManager.AddTask(Task);
	}
	//3.�V�[���J��
	{
		QueueTaskManager::FTask Task;
		Task.BindLambda([&]() {
			SceneChange(NextSceneName);
			return true;
		});
		TaskManager.AddTask(Task);
	}
}

void APlayerDieEvent::StartLockerDieEvent(APlayerCharacter* Player, AEnemy* Enemy, ALocker* Locker)
{
	auto MakeTimer = [&](float Time) {
		return [&, time = Time]() mutable {
			time -= GetWorld()->GetDeltaSeconds();
			return time;
		};
	};

	if (bIsStartedEvent)
		return;
	this->bIsStartedEvent = true;
	InitPostProcess();

	//���b�J�[���̎��S�C�x���g
	//1.���b�J�[�̃h�A���J��
	{
		QueueTaskManager::FTask Task;
		Task.BindLambda([&, Locker]() {
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Open"));
			Locker->OpenDoor(0.25f, true);
			return true;
		});
		TaskManager.AddTask(Task);
	}
	//2.�J���܂őҋ@
	{
		QueueTaskManager::FTask Task;
		Task.BindLambda([&, Locker]() {
			GEngine->AddOnScreenDebugMessage(-1, 1.0f, FColor::Red, TEXT("Wait Open"));
			return Locker->IsOpenedDoor();
		});
		TaskManager.AddTask(Task);
	}
	//3.�G��Kill�A�j���[�V�����܂őҋ@
	{
		QueueTaskManager::FTask Task;
		Task.BindLambda([&, Timer = MakeTimer(WaitTime)]() mutable {
			return Timer() <= 0.0f;
		});
		TaskManager.AddTask(Task);
	}
	//4.�V�[���J��
	{
		QueueTaskManager::FTask Task;
		Task.BindLambda([&]() {
			SceneChange(NextSceneName);
			return true;
		});
		TaskManager.AddTask(Task);
	}
}
