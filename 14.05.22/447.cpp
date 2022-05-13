#include <iostream>

using namespace std;

int main()
{
    long long  n, num = 1;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        num *= i;
        while (num % 10 == 0) num /= 10;
        num %= 1000000;
    }

    cout << num % 10;

    return 0;
}
