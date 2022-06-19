#pragma once

#include "ArrayList.h"

class ExQueue
{
public:
	ExQueue();
	~ExQueue();

	bool IsEmpty() const;
	int Length() const;
	void Print() const;

	void Enqueue(int element);
	int Dequeue();
	int Peek();

private:
	ArrayList internalList;
};

//.cpp

ExQueue::ExQueue()
{
}

ExQueue::~ExQueue()
{
}

bool ExQueue::IsEmpty() const
{
    return internalList.Length() == 0;
}

int ExQueue::Length() const
{
    return internalList.Length();
}

void ExQueue::Print() const
{
    internalList.Print();
}

void ExQueue::Enqueue(int element)
{
    internalList.Append(element);
}

int ExQueue::Dequeue()
{
    if (IsEmpty())
        return -1;

    int element = Peek();
    internalList.DeleteAt(0);
    return element;
}

int ExQueue::Peek()
{
    if (IsEmpty())
        return -1;

    return internalList[0];
}

