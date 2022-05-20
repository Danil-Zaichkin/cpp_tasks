#include <iostream>
#include <map>

using namespace std;

int main() {
    
    map<int, long long> dict;
    dict.emplace(2, 1);
    int k, p;
    cin >> k >> p;
    if (k == 1) {
        cout << 0;
        return 0;
    }
    for (int i = 3; i <= k; ++i) {
        if (i % 2 == 1) {
            dict.emplace(i, dict[i - 1] % p);
        } else {
            dict.emplace(i, (dict[i - 1] + dict[i / 2]) % p);
            dict.erase(i / 2);
        }
    }
    cout << dict[k];
    return 0;
}
