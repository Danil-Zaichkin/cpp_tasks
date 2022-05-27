#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, W;
    cin >> n >> W;
    vector <int> w(n + 1);
    vector <int> c(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    vector<vector<int>> dp(n + 1, vector<int>(W + 1, -100000000));
    dp[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            if (w[i] <= j)
                dp[i][j] = max(dp[i-1][j], dp[i-1][i-w[i]]+c[i]);
            else
                dp[i][j] = dp[i-1][j];
        }
    }

    int ans = 0;
    for (int i = 0; i <= W; i++) {
        ans = max(ans, dp[n][i]);
    }
    for (auto i : dp) {
        for (auto j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }
    cout << ans << endl;
    return 0;
}