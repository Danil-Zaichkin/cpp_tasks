#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long res = pow(3, n / 3);
    if (n % 3 == 1)
        res = res * 4 / 3;
    if (n % 3 == 2)
        res = res * 2;
    cout << res;
}
