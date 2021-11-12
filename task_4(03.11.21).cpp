#include<iostream>;
#include<string>;

using namespace std;

int main() {
	string input;
	getline(cin, input);

	int i = 0;
	while (i < input.size()) {
		if (input[i] == ' ' && input[i + 1] == ' ') {
			input.erase(i + 1, 1);
		}
		else {
			i++;
		}
	}
	
	cout << input << endl;
}
