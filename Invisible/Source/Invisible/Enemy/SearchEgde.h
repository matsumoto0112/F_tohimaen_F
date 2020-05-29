// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

#include "SearchEgde.generated.h"

UCLASS()
class INVISIBLE_API ASearchEgde : public AActor
{
	GENERATED_BODY()

public:
	// �R���X�g���N�^
	ASearchEgde();

protected:
	// �����ݒ�
	virtual void BeginPlay() override;

public:
	// �X�V
	virtual void Tick(float DeltaTime) override;
	// Tick�̏������G�f�B�^��ł��s���悤�ɂ���
	virtual bool ShouldTickIfViewportsOnly() const override { return true; };

	// �G���A���a�ݒ�
	void SetRadius(float r);
	// �G���A���a�擾
	float GetRadius() const;
	// ����ݒ�
	void SetBranch();
	// �����
	TArray<ASearchEgde*> GetBranch() const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// �͈͔��a
	float radius = 100.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// ����
	TArray<ASearchEgde*> branch;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// �f�o�b�O�\��
	bool debugDraw;
};
