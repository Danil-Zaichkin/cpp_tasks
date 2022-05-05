#include <iostream>

using namespace std;

int main() {
    string n;
    long long k;
    cin >> n;
    cin >> k;
    int i = 0;
    long long ans = 0;
    while (i < n.length()) {
        while (ans < k)
            ans = ans * 10 + n[i++] - '0';
        ans = ans % k;
    }
    cout << ans;
}

