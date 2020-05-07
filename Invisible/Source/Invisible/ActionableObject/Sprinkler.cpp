// Fill out your copyright notice in the Description page of Project Settings.

#include "Sprinkler.h"

#include "Invisible/ActionableObject/PuddleFactory.h"
#include "Invisible/System/MyGameInstance.h"
#include "Invisible/System/SoundSystem.h"

//�R���X�g���N�^
ASprinkler::ASprinkler()
{
	PrimaryActorTick.bCanEverTick = true;

	//���b�V���R���|�[�l���g���쐬����
	meshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = meshComponent;

	//�p�[�e�B�N�����쐬����
	particleComponent = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleComponent"));
	particleComponent->AttachToComponent(RootComponent,
	    FAttachmentTransformRules(
	        EAttachmentRule::KeepRelative,
	        EAttachmentRule::KeepRelative,
	        EAttachmentRule::KeepRelative,
	        false));

	wetArea = CreateDefaultSubobject<UBoxComponent>(TEXT("WetArea"));
	wetArea->InitBoxExtent(FVector(250.0f, 200.0f, 250.0f));
	wetArea->SetRelativeLocation(FVector(0.0f, -220.0f, 0.0f));
	wetArea->SetGenerateOverlapEvents(false);
	wetArea->SetSimulatePhysics(false);
	wetArea->SetCollisionProfileName("OverlapAllDynamic");
	wetArea->SetupAttachment(RootComponent);
}

void ASprinkler::BeginPlay()
{
	Super::BeginPlay();
	puddleSpawned = false;

	//�p�[�e�B�N�����Q�[���J�n���ɒ�~������
	if (particleComponent)
	{
		particleComponent->SetEmitterEnable(particleEmitterName, false);
	}
}

void ASprinkler::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);

	//�p�[�e�B�N���̏I���^�C�}�[����������
	GetWorldTimerManager().ClearAllTimersForObject(this);
}

//�A�N�V�����̎���
void ASprinkler::action_Implementation()
{
	particleComponent->SetEmitterEnable(particleEmitterName, true);
	wetArea->SetGenerateOverlapEvents(true);

	//�^�C�}�[���ғ����Ȃ�㏑������
	if (timerHandle.IsValid())
	{
		GetWorldTimerManager().ClearTimer(timerHandle);
	}
	//��莞�Ԍ�Ƀp�[�e�B�N���𖳌��ɂ���
	GetWorldTimerManager().SetTimer(timerHandle, [&]() {
		particleComponent->SetEmitterEnable(particleEmitterName, false);
		wetArea->SetGenerateOverlapEvents(false);
	},
	    activeTime, false);

	//�X�v�����N���[�̉����Đ�����
	UMyGameInstance::GetInstance()->getSoundSystem()->play3DSound(ESoundType::Sprinkler, GetActorLocation(), this);

	//�����܂肪���łɂ���Ȃ牽�����Ȃ�
	if (puddleSpawned)
		return;

    //���x�����琅���܂萶������擾����
	AActor* aFactory = UGameplayStatics::GetActorOfClass(GetWorld(), APuddleFactory::StaticClass());
	if (!aFactory)
		return;
	if (!Cast<APuddleFactory>(aFactory))
		return;

	APuddleFactory* factory = Cast<APuddleFactory>(aFactory);

	//�����܂�̔����|�C���g���ׂĂɐ����܂��z�u����
	for (auto& point : puddlePoints)
	{
		factory->spawnRandomPuddle(point->GetActorLocation());
	}
	puddleSpawned = true;
}

void ASprinkler::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
