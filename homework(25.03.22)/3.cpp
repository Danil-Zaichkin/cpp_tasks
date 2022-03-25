#include <iostream>

using namespace std;

class vStack {
	int size;
	int sp;
	int vsp;
	int* stArr;
	int** vArr= new int* [30];
	int* spArr = new int[30];

public:
	vStack(int s) {
		size = s;
		stArr = new int[size];
		sp = 0;
		vsp = 0;
		for (int i = 0; i < 30; i++) {
			vArr[i] = new int[size];
		}
	}

	~vStack() {
		delete[] stArr;
		delete[] spArr;
		for (int i = 0; i < 30; i++) {
			delete[] vArr[i];
		}
		delete[] vArr;
	}

	bool push(int item) {
		if (sp < size) {
			stArr[sp++] = item;
			vsp++;
			for (int i = 0; i < size; i++) {
				vArr[vsp][i] = stArr[i];
			}
			spArr[vsp] = sp;
			return true;

		}
		return false;
	}

	int top() {
		return stArr[sp-1];
	}

	void pop() {
		sp--;
		vsp++;
		for (int i = 0; i < size; i++) {
			vArr[vsp][i] = stArr[i];
		}
		spArr[vsp] = sp;
	}

	void rollback(int n) {
		vsp -= n;
		for (int i = 0; i < size; i++)
			stArr[i] = vArr[vsp][i];
		sp = spArr[vsp];
	}

	void forget() {
		vsp = 0;
	}
};

int main() {
	vStack st(5);

	st.push(1);
	st.push(2);
	st.rollback(1);
	cout << st.top();
}
