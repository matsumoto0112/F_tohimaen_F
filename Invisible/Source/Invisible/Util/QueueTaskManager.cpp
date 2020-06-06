// Fill out your copyright notice in the Description page of Project Settings.

#include "QueueTaskManager.h"

QueueTaskManager::QueueTaskManager()
{
}

QueueTaskManager::~QueueTaskManager()
{
	Clear();
}

void QueueTaskManager::Update()
{
	if (Tasks.IsEmpty())
		return;

    if (Tasks.Peek()->Execute())
	{
		Tasks.Pop();
	}
}

void QueueTaskManager::AddTask(const FTask& Task)
{
	Tasks.Enqueue(Task);
}

void QueueTaskManager::Clear()
{
	Tasks.Empty();
}
