#include <iostream>

using namespace std;

class Queue {
	int size;
	int* queArr;
	int currentItem;

public:
	Queue(int s) {
		size = s;
		queArr = new int[size];
		currentItem = 0;
	}

	~Queue() {
		delete[] queArr;
	}

	bool push(int item) {
		if (currentItem == size) return false;
		else{
			queArr[currentItem++] = item;
			return true;
		}
		
	}

	void pop() {
		for (int i = 0; i < currentItem-1; i++) {
			queArr[i] = queArr[i + 1];
		}
		currentItem--;
	}

	int top() {
		return queArr[0];
	}
};
