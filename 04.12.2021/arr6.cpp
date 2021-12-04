#include <iostream>

using namespace std;

int nod(int a, int b) {
    while (a > 0 && b > 0)
        if (a > b)
            a = a%b;
        else
            b = b%a;
    return a+b;
}
int main () {
    int m;
    int n;
    cin >> m >> n;
    --n; --m;
    if (m == n) {
        cout << n;
        return 0;
    }
    int gcd = nod(m, n);
    cout << n + m - gcd;
    return 0;
}
