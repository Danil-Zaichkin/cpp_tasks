#include <iostream>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (m == 1)
        cout << n;
    else if (m % 2 == 0)
        cout << m/2;
    else {
        int ans = 0;
        while (m % 2 != 0 and n != 1) {
            ans += (n-(n%2)) / 2;
            n -= (n-(n%2)) / 2;
            m -=  (m-(m%2)) / 2;
        }

        cout << ans + m/2;
    }
}
