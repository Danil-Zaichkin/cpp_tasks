#pragma once

struct Node
{
	int data;
	Node* pNext;
};

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void Print() const;

	void AppendBack(int element);
	void AppendFront(int element);
	void InsertAfter(Node* pNode, int element);

	void DeleteAfter(Node* pPrevNode);

private:
	Node* pHead;
	Node* pTail;
};

//.cpp

#include <iostream>


using namespace std;

LinkedList::LinkedList()
{
    pHead = nullptr;
    pTail = nullptr;
}

LinkedList::~LinkedList()
{
    Node* pTemp = pHead;
    while (pTemp != nullptr)
    {
        Node* pDeleteNode = pTemp;
        pTemp = pTemp->pNext;
        delete pDeleteNode;
    }
}

void LinkedList::Print() const
{
    Node* pTemp = pHead;
    while (pTemp != nullptr)
    {
        cout << pTemp->data << " ";
        pTemp = pTemp->pNext;
    }
    cout << endl;
}

void LinkedList::AppendBack(int element)
{
    Node* pNode = new Node();
    pNode->data = element;
    pNode->pNext = nullptr;

    if (pTail == nullptr)
    {
        pHead = pNode;
        pTail = pNode;
    }

    pTail->pNext = pNode;
    pTail = pNode;
}

void LinkedList::AppendFront(int element)
{
    Node* pNode = new Node();
    pNode->data = element;
    pNode->pNext = nullptr;

    if (pHead == nullptr)
    {
        pHead = pNode;
        pTail = pNode;
    }

    pNode->pNext = pHead;
    pHead = pNode;
}

void LinkedList::InsertAfter(Node* pNode, int element)
{
    Node* newNode = new Node();
    newNode->data = element;
    newNode->pNext = pNode->pNext;
    pNode->pNext = newNode;
}

void LinkedList::DeleteAfter(Node* pPrevNode)
{
    Node* pTemp = pPrevNode->pNext;
    pPrevNode->pNext = pTemp->pNext;
    delete pTemp;
}
