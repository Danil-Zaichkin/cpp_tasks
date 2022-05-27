#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int n3 = n/3;
    int n2 = 0;
    if (n % 3 == 1) {
       n3--;
       n2 += 2;
    } else if (n % 3 == 2) {
        n2++;
    }
    if (n2 != 0 and n3 != 0) {
        cout << 2 << ' ' << n2 << ' ' << 3 << ' ' << n3;
    } else if (n3 != 0) {
        cout << 3 << ' ' << n3;
    } else {
        cout << 2 << ' ' << n2;
    }

    return 0;
}