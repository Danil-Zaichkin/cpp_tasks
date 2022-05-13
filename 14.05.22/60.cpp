#include <iostream>

using namespace std;

bool isprime(int n) {
    if (n == 1) return false;
    int m = 2;
    while (m * m <= n) {
        if (n % m == 0)
            return false;
        m += 1;
    }
    return true;
}



int main() {
    int k;
    cin >> k;
    int i_prime= 1;
    int i_super_prime = 0;
    int n = 2;
    int ans;
    while (true) {  
        if (isprime(n)) {
            if (isprime(i_prime)) {
                i_super_prime++;
                if (k == i_super_prime) {
                    cout << n;
                    break;
                }
            }
            i_prime++;
        }
        n++;
    }

    return 0;
}
