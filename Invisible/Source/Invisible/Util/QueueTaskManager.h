// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine.h"

/**
 * キュー式タスク管理
 * @details タスク（関数）をその結果がtrueになるまでUpdateを呼ばれるたびに実行し、trueになったら次のタスクを実行するシステム
 */
class INVISIBLE_API QueueTaskManager
{
public:
	//!< 実行タスクリスト
	DECLARE_DELEGATE_RetVal(bool, FTask);

public:
    /**
    * コンストラクタ
    */
	QueueTaskManager();
    /**
    * デストラクタ
    */
	~QueueTaskManager();
    /**
    * 更新する
    */
	void Update();
    /**
    * 追加する
    */
	void AddTask(const FTask& Task);
    /**
    * タスクのクリア
    */
	void Clear();

private:
	TQueue<FTask> Tasks;
};
