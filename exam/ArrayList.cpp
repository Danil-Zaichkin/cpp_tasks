#pragma once

class ArrayList
{
public:
	ArrayList();
	~ArrayList();

	int Get(int idx) const;
	int Length() const;
	void Print() const;

	void Append(int element);
	bool InsertAt(int element, int idx);
	bool DeleteAt(int idx);
	int IndexOf(int element);

	int operator[](int idx);

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

ArrayList::ArrayList()
{
    capacity = 4;
    growFactor = 2;
    size = 0;
    pInt = new int[capacity];
}

ArrayList::~ArrayList()
{
    delete[] pInt;
}

int ArrayList::Get(int idx) const
{
    if (idx < 0 || idx > size)
        return -1;
    return pInt[idx];
}

int ArrayList::Length() const
{
    return size;
}

void ArrayList::Print() const
{
    for (int i = 0; i < size; ++i)
        cout << pInt[i] << " ";
    cout << endl;
}

void ArrayList::Append(int element)
{
    if (size == capacity)
        Resize();

    pInt[size] = element;
    size++;
}

bool ArrayList::InsertAt(int element, int idx)
{
    if (idx < 0 || idx > size)
        return false;

    if (size == capacity)
        Resize();

    size++;

    for (int i = size - 1; i > idx; i--)
        pInt[i] = pInt[i - 1];

    pInt[idx] = element;
    return true;
}

bool ArrayList::DeleteAt(int idx)
{
    if (idx < 0 || idx > size)
        return false;

    for (int i = idx; i < size; i++)
        pInt[i] = pInt[i + 1];

    size--;
    return true;
}

int ArrayList::IndexOf(int element)
{
    if (size == 0)
        return -1;

    int idx = -1;
    for (int i = 0; i < size; ++i)
        if (pInt[i] == element)
            return i;

    return -1;
}

int ArrayList::operator[](int idx)
{
    return Get(idx);
}

void ArrayList::Resize()
{
    capacity = capacity * growFactor;
    int* pTemp = new int[capacity];
    Copy(pTemp);
    delete[] pInt;
    pInt = pTemp;
}

void ArrayList::Copy(int* pTemp)
{
    /*
    for (int i = 0; i < size; i++)
        pTemp[i] = pInt[i];
    */

    int sizeInBytes = size * sizeof(int);
    memcpy_s(pTemp, sizeInBytes, pInt, sizeInBytes);
}
