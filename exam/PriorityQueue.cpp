#pragma once

#include "ArrayList.h"

class PriorityQueue
{
public:
	PriorityQueue();
	~PriorityQueue();

	bool IsEmpty() const;
	int Length() const;
	void Print() const;

	void Enqueue(int element, int priority);
	int Dequeue();
	int Peek();

private:
	ArrayList internalList;
	ArrayList priorityList;
};

//.cpp

PriorityQueue::PriorityQueue()
{
}

PriorityQueue::~PriorityQueue()
{
}

bool PriorityQueue::IsEmpty() const
{
    return internalList.Length() == 0;
}

int PriorityQueue::Length() const
{
    return internalList.Length();
}

void PriorityQueue::Print() const
{
    internalList.Print();
}

void PriorityQueue::Enqueue(int element, int priority)
{
    int idx = 0;
    while (idx < priorityList.Length())
    {
        if (priorityList[idx] < priority)
            break;
        ++idx;
    }

    internalList.InsertAt(element, idx);
    priorityList.InsertAt(priority, idx);
}

int PriorityQueue::Dequeue()
{
    if (IsEmpty())
        return -1;

    int element = Peek();
    internalList.DeleteAt(0);
    priorityList.DeleteAt(0);
    return element;
}

int PriorityQueue::Peek()
{
    if (IsEmpty())
        return -1;

    return internalList[0];
}
