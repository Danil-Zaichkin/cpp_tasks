#pragma once

class Stack
{
public:
	Stack();
	~Stack();

	bool IsEmpty() const;
	int Length() const;
	void Print() const;

	void Push(int element);
	int Pop();
	int Peek();

private:
	void Resize();
	void Copy(int* pTemp);

	int* pInt;
	int size;
	int capacity;
	int growFactor;
};

//.cpp
#include <iostream>

using namespace std;

Stack::Stack()
{
    capacity = 4;
    growFactor = 2;
    size = 0;
    pInt = new int[capacity];
}

Stack::~Stack()
{
    delete[] pInt;
}

bool Stack::IsEmpty() const
{
    return size == 0;
}

int Stack::Length() const
{
    return size;
}

void Stack::Print() const
{
    for (int i = 0; i < size; ++i)
        cout << pInt[i] << " ";
    cout << endl;
}

void Stack::Push(int element)
{
    if (size == capacity)
        Resize();

    pInt[size] = element;
    size++;
}

int Stack::Pop()
{
    --size;
    return pInt[size];
}

int Stack::Peek()
{
    return pInt[size - 1];
}

void Stack::Resize()
{
    capacity = capacity * growFactor;
    int* pTemp = new int[capacity];
    Copy(pTemp);
    delete[] pInt;
    pInt = pTemp;
}

void Stack::Copy(int* pTemp)
{
    /*
    for (int i = 0; i < size; i++)
        pTemp[i] = pInt[i];
    */

    int sizeInBytes = size * sizeof(int);
    memcpy_s(pTemp, sizeInBytes, pInt, sizeInBytes);
}
