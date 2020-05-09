// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyDetectArea.h"

#include "Engine.h"
#include "Kismet/GameplayStatics.h"

//�R���X�g���N�^
UEnemyDetectArea::UEnemyDetectArea()
{
	SphereRadius = 1000.0f;

	this->OnComponentBeginOverlap.AddDynamic(this, &UEnemyDetectArea::BeginOverlapEvent);
	this->OnComponentEndOverlap.AddDynamic(this, &UEnemyDetectArea::EndOverlapEvent);
}

void UEnemyDetectArea::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
}

//���m�ƌx��
void UEnemyDetectArea::DetectAndWarn()
{
	const FVector Location = GetComponentLocation();
	for (auto&& Enemy : Enemies)
	{
		//���łɌx�����Ă����牽�����Ȃ�
		if (Enemy.bWarned)
			continue;

		//���C���΂��ĊԂɏ�Q�����Ȃ������ׂ�
		//NOTE:�}�b�v�̍\���㍡���郂�W���[�����烌�C���΂��Ă��Փ˂��Ȃ����߁A�p�ɗ����Ă���Ƃ��ȂǊԂɕǂ�����ꍇ�ł���{�I�ɕǂ͔�����Ƃ�Ȃ�
		//�ł����̂ق������ǂ̐�ɓG�����Ă����m�ł���̂œs�����悭�A���̂܂܂ɂ��Ă���
		const FVector EnemyLocation = Enemy.Enemy->GetActorLocation();
		FHitResult Result;
		if (GetWorld()->LineTraceSingleByChannel(Result, Location, EnemyLocation, ECollisionChannel::ECC_Visibility))
		{
			//�Ԃɏ�Q�����Ȃ���Όx���𔭂���
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

//�����ƃI�[�o�[���b�v����
void UEnemyDetectArea::BeginOverlapEvent(UPrimitiveComponent* HitComp, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
    if (CheckOverlappingsActorIsEnemy(OtherActor, OtherComp))
    {
        BeginOverlapEnemy(Cast<AEnemy>(OtherActor));
    }
}

//�����ƃI�[�o�[���b�v����������
void UEnemyDetectArea::EndOverlapEvent(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor,
    UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
    if (CheckOverlappingsActorIsEnemy(OtherActor,OtherComp))
    {
        EndOverlapEnemy(Cast<AEnemy>(OtherActor));
    }
}

//�A�N�^�[���G���ǂ������肷��
bool UEnemyDetectArea::CheckOverlappingsActorIsEnemy(AActor* OtherActor, UPrimitiveComponent* OtherComp)
{
	AEnemy* Enemy = Cast<AEnemy>(OtherActor);
    //�G�̃v���C���[���m�͈͂��Ƃ邱�Ƃ������A���̏ꍇ�A�ǉz���ł���邱�Ƃ������̂œG�̃��f�����擾���Ĕ��肵�Ă���
    USkeletalMeshComponent* Skeltal = Cast<USkeletalMeshComponent>(OtherComp);
	return Enemy && Skeltal;
}

//�G�ƃI�[�o�[���b�v����
void UEnemyDetectArea::BeginOverlapEnemy(AEnemy* Enemy)
{
    //�G���X�g�ɒǉ�����
	Enemies.Add({Enemy, false});
}

//�G�ƃI�[�o�[���b�v��������
void UEnemyDetectArea::EndOverlapEnemy(AEnemy* Enemy)
{
    //�G���X�g����O��
	Enemies.RemoveAll([Enemy](FEnemyDetect& detect) { return detect.Enemy == Enemy; });
}
