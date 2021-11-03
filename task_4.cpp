#include <iostream>;
#include <string>;

using namespace std;

int main() {
	string input, res;
	getline(cin, input);
	for (int i = 0; i < input.size(); i++) {
		if (input[i] != ' ')
			res += input[i];
	}
	cout << res;
	return 0;
}
