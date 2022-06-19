#pragma once

#include "ArrayList.h"

class ExStack
{
public:
	ExStack();
	~ExStack();

	bool IsEmpty() const;
	int Length() const;
	void Print() const;

	void Push(int element);
	int Pop();
	int Peek();

private:
	ArrayList internalList;
};

//.cpp

ExStack::ExStack()
{
}

ExStack::~ExStack()
{
}

bool ExStack::IsEmpty() const
{
    return internalList.Length() == 0;
}

int ExStack::Length() const
{
    return internalList.Length();
}

void ExStack::Print() const
{
    internalList.Print();
}

void ExStack::Push(int element)
{
    internalList.Append(element);
}

int ExStack::Pop()
{
    int element = Peek();
    internalList.DeleteAt(internalList.Length() - 1);
    return element;
}

int ExStack::Peek()
{
    return internalList.Get(internalList.Length() - 1);
}
