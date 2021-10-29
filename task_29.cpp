#include <iostream>;

using namespace std;

void main() {
	int a = 2;
	while (a <= 100) {
		if (a % 2 == 0)
			cout << a << endl;
		a++;
	}
}
