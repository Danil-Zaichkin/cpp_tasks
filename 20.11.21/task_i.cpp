#include <iostream>

using namespace std;

void prime_factors(int n, int prime) {
    if (n == 1)
        return;
    if (n % prime == 0) {
        cout << prime << " ";
        prime_factors(n / prime, prime);
    } else {
        prime_factors(n, prime + 1);
    }
}

int main() {
    int n;
    cin >> n;
    prime_factors(n, 2);
    return 0;
}
