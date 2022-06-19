#pragma once

class Queue
{
public:
	Queue();
	~Queue();

	bool IsEmpty() const;
	int Length() const;
	void Print() const;

	void Enqueue(int element);
	int Dequeue();
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

Queue::Queue()
{
    capacity = 4;
    growFactor = 2;
    size = 0;
    pInt = new int[capacity];
}

Queue::~Queue()
{
    delete[] pInt;
}

bool Queue::IsEmpty() const
{
    return size == 0;
}

int Queue::Length() const
{
    return size;
}

void Queue::Print() const
{
    for (int i = 0; i < size; ++i)
        cout << pInt[i] << " ";
    cout << endl;
}

void Queue::Enqueue(int element)
{
    if (size == capacity)
        Resize();

    pInt[size] = element;
    size++;
}

int Queue::Dequeue()
{
    if (size == 0)
        return -1;

    int element = pInt[0];

    for (int i = 0; i <= size; i++)
        pInt[i] = pInt[i + 1];

    size--;
    return element;
}

int Queue::Peek()
{
    if (size == 0)
        return -1;

    return pInt[size];
}

void Queue::Resize()
{
    capacity = capacity * growFactor;
    int* pTemp = new int[capacity];
    Copy(pTemp);
    delete[] pInt;
    pInt = pTemp;
}

void Queue::Copy(int* pTemp)
{
    /*
    for (int i = 0; i < size; i++)
        pTemp[i] = pInt[i];
    */

    int sizeInBytes = size * sizeof(int);
    memcpy_s(pTemp, sizeInBytes, pInt, sizeInBytes);
}
