// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SearchEgde.h"

#include "SearchManager.generated.h"

class SearchCourse;

UCLASS()
class INVISIBLE_API ASearchManager : public AActor
{
	GENERATED_BODY()

public:
	// �R���X�g���N�^
	ASearchManager();

protected:
	// �����X�V
	virtual void BeginPlay() override;

public:
	// �X�V
	virtual void Tick(float DeltaTime) override;

	// �o�H�ݒ�
	TArray<FVector> Course(AActor* actor) const;
	//�o�H�ݒ�
	TArray<FVector> Course(AActor* start, AActor* end) const;
	//�o�H�ݒ�
	TArray<FVector> Course(FVector start, FVector end) const;
	//�ǐՌo�H�ݒ�
	TArray<FVector> ChaseCourse(AActor* start, AActor* end) const;
	//�ǐՌo�H�ݒ�
	TArray<FVector> ChaseCourse(FVector start, FVector end) const;
	//�@�G���A���a�擾
	float GetRadius() const;

	// �ߕӂ̕���ӏ��擾
	FVector NearSearchPosition(AActor* actor) const;
	// �ߕӂ̕���ӏ��擾
	FVector NearSearchPosition(FVector point) const;

	// �ړ��ӏ��Ƃ̊Ԃɏ�Q�������邩����
	bool DirectionSearch(AActor* actor, FVector near) const;
	// �ړ��ӏ��Ƃ̊Ԃɏ�Q�������邩����
	bool DirectionSearch(AActor* actor, ASearchEgde* near) const;

private:
	// �ߕӂ̕���ӏ��擾
	ASearchEgde* NearSearch(AActor* actor) const;
	// �ߕӂ̕���ӏ��擾
	ASearchEgde* NearSearch(FVector point) const;
	// �����_���ɕ���ӏ��擾
	ASearchEgde* GetRandomSearch(ASearchEgde* remove) const;
	// �ustart >> end�v�Ɍ������o�H�ݒ�
	TArray<FVector> Course(SearchCourse* start, ASearchEgde* end) const;


protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// �T���ӏ�
	TArray<ASearchEgde*> search;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	// �G���A���a
	float radius = 100.0f;

	// �v���C���[
	AActor* player;
	// �G
	TArray<AActor*> enemys;
};
