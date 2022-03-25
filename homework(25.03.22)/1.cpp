#include <iostream>
#include <stack>
#include <string>

using namespace std;

int priority(char ch) {
	switch (ch) {
		case '+': return 0;
		case '-': return 0;
		case '*': return 1;
		case '/': return 1;
		case '^': return 2;
	}
	return -1;
};

void print(stack <int> st) {
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
	cout << endl;
}

int main() {
	string input;
	cin >> input;
	string output = "";
	stack <char> steck;	

	for (char i : input) {

		if ((int)i < 58 and (int)i > 47) {
			output += i;
		}
		else if (i == '(') {
			steck.push(i);
		}
		else if (i == ')') {
			while (steck.top() != '(') {
				output += steck.top();
				steck.pop();
			}
		}
		else if (steck.empty() or priority(steck.top()) < priority(i)) {
			steck.push(i);
		}
		else if (priority(steck.top()) >= priority(i)) {
			output += steck.top();
			steck.pop();
			steck.push(i);
		}
		
	}
	while (!steck.empty()) {
		if (steck.top() != '(') {
			output += steck.top();
			steck.pop();
		}
		
	}
	cout << output << endl;;

	stack <int> st;
	for (char i : output) {
		if ((int)i < 58 && (int)i > 47) {
			cout << (int)i - 48 << endl;
			st.push((int)i-48);
		}
		else {
			int num1 = st.top();
			st.pop();
			int num2 = st.top();
			st.pop();
			cout << num1 << ' ' << num2 << endl;
			if (i == '+') st.push(num2 + num1);
			else if (i == '-') st.push(num2 - num1);
			else if (i == '*') st.push(num2 * num1);
			else if (i == '/') st.push(num2 / num1);
			else if (i == '^') st.push(pow(num2, num1));
			print(st);
		}
	}
	cout << st.top();
	return 0;
}
