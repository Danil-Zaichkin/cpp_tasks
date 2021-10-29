#include <iostream>;

using namespace std;

void main() {
	int a;
	int n;
	int ans = 1;
	cin >> a;
	cin >> n;
	for (int i = 0; i < n; i++) {
		ans *= a + i;
	}
	cout << ans;
}
