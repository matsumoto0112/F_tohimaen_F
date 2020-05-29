// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SearchEgde.h"

/**
 * 
 */
class INVISIBLE_API SearchCourse
{
public:
	// �R���X�g���N�^
	SearchCourse(ASearchEgde* baseSearch);
	// �R���X�g���N�^
	SearchCourse(ASearchEgde* baseSearch, SearchCourse* parentSearch);

	// ���ݒn
	ASearchEgde* GetBaseSearch() const;
	// �ړ���ݒ�
	TArray<SearchCourse*> SetChild(const TArray<SearchCourse*> remove);
	// �o�H�擾
	TArray<SearchCourse*> GetParents();
	// ���_�擾
	SearchCourse* MostParent();
	// ���_���猻�ݒn�܂ł̋���
	double Length();

private:
	// �o�H�擾
	TArray<SearchCourse*> GetParents(TArray<SearchCourse*> parents);

private:
	// ���ݒn
	ASearchEgde* baseSearch;
	// �ړ���
	SearchCourse* parentSearch;
	// �ړ���
	TArray<SearchCourse*> childSearch;
};
