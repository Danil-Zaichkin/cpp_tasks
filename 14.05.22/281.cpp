#include <iostream>
#include <vector>

using namespace std;


int main() {
    
    vector<long long> fact;
    long long n, m;
    int tmp = 1, now = 1, ans = 0;
    cin >> n >> m;
    fact.push_back(1);
    while (tmp != n + 1) {
        now *= tmp;
        fact.push_back(now);
        tmp++;
    }
    for (int i = m; i <= n; ++i) {
        ans += fact[n] / (fact[i] * fact[n - i]);
    }
    cout << ans;
    
    return 0;
}
