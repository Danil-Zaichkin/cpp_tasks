#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


int main() {
    
    vector<int> mas;
    int n, h1, m1, h2, m2;
    int ans = 0;
    cin >> n;
    for (int i = 0; i < 1440; ++i) {
        mas.push_back(0);
    }
    for (int i = 0; i < n; ++i) {
        cin >> h1 >> m1 >> h2 >> m2;
        if (h1 * 60 + m1 < h2 * 60 + m2) {
            for (int j = h1 * 60 + m1; j < h2 * 60 + m2; ++j) {
                mas[j]++;
            }
        }
        else if (h1 * 60 + m1 == h2 * 60 + m2) {
            for (int j = 0; j < 1440; ++j) {
                mas[j]++;
            }
        }
        else {
            for(int j = h1 * 60 + m1; j < 1440; ++j) {
                mas[j]++;
            }
            for (int j = 0; j < h2 * 60 + m2; ++j) {
                mas[j]++;
            }
        }
    }
    for (int i = 0; i < 1440; ++i) {
        if (mas[i] == n) {
            ans++;
        }
    }
    cout << ans;
    return 0;
}
