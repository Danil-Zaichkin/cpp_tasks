#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long n;
    cin >> n;
    long long k = n / 2 + (n % 2 -1)*(1 + (n / 2) % 2);
    cout << k << ' ' << n-k;
}

