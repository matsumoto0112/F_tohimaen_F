// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"

/**
 * �L���[���^�X�N�Ǘ�
 * @details �^�X�N�i�֐��j�����̌��ʂ�true�ɂȂ�܂�Update���Ă΂�邽�тɎ��s���Atrue�ɂȂ����玟�̃^�X�N�����s����V�X�e��
 */
class INVISIBLE_API QueueTaskManager
{
public:
	//!< ���s�^�X�N���X�g
	DECLARE_DELEGATE_RetVal(bool, FTask);

public:
    /**
    * �R���X�g���N�^
    */
	QueueTaskManager();
    /**
    * �f�X�g���N�^
    */
	~QueueTaskManager();
    /**
    * �X�V����
    */
	void Update();
    /**
    * �ǉ�����
    */
	void AddTask(const FTask& Task);
    /**
    * �^�X�N�̃N���A
    */
	void Clear();

private:
	TQueue<FTask> Tasks;
};
