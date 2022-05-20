#include <iostream>
#include <string>

using namespace std;

int main() {
    string n;
    int k;
    
    cin >> n >> k;
    int c = 0;
    long long t = 0;
    bool flag = 0;
    while (c < n.length()) {
        while (t < k && c < n.length()) {
            t = t * 10 + n[c] - '0';
            if (t < k && flag) cout << 0;
            c++;
        }
        if (t < k and !flag) {
            cout << 0;
            return 0;
        }
        flag = 1;
        if (t >= k)
            cout << t / k;
        t %= k;
    }
    return 0;
}
