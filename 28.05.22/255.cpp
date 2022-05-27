#include <iostream>

using namespace std;

int getDivider(long long n) {
    int k = 2;
    while (k * k <= n) {
        if (n % k == 0)
            return k;
        k++;
    }
    return n;
}

int main()
{
    long long n;
    cin >> n;
        long long div = getDivider(n);
        if (n == div) {
            cout << 1 << ' ' << n - 1  << endl;
        } else {
            cout << n / div << ' ' << n - (n / div) << endl;
        }
    return 0;
}