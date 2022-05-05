#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> mas(n, vector<int>(n));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mas[i][j];

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j and mas[i][k] != -1 and mas[k][j] != -1) {
                    if (mas[i][j] == -1)
                        mas[i][j] = mas[i][k] + mas[k][j];
                    else
                        mas[i][j] = min(mas[i][j], mas[i][k] + mas[k][j]);
                }
            }
        }
    }

    int ans = 0;
    for (const auto& i : mas) {
        for (auto j : i) {
            ans = max(ans, j);
        }
    }
    cout << ans;
}
