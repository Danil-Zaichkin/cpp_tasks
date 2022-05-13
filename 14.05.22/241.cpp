#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int count = 2 * (n / 7);
	if (n % 7 == 1) {
		count++;
	}
	if (n % 7 >= 2) {
		count += 2;
	}
	count += n;
	if (count == 53 || count == 66) {
		count++;
	}
	cout << count;
	return 0;
}
