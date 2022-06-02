#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> mas;
int n, l;
int u, v;
vector<bool> used;
vector<int> p;
vector<int> d;
vector<vector<int>> dp;



void dfs(int v, int depth) {
    used[v] = true;
    d[v] = depth;



    for (int i = 0; i < n; i++) {
        if (mas[v][i] and !used[i]) {
            p[i] = v;
            dfs(i, depth+1);
        }
    }
}

void prepairLCA() {
    p.resize(n);
    d.resize(n);
    dp.resize(n);
    used.resize(n);

    l = int(log2(n));
    //while ((1 << l) <= n) l++;
    for (int i = 0 ; i < n; i++){
        dp[i].resize(l);
    }

    p[0] = 0;
    dfs(0, 0);

    for (int i = 1; i < n; i++)
        dp[i][0] = p[i];
    for (int j = 1; j < l; j++) {
        for (int i = 1; i < n; i++)
            dp[i][j] = dp[dp[i][j - 1]][j - 1];
    }
}

int LCA(int v, int u) {
    if (d[v] > d[u]) {
        int tmp = v;
        v = u;
        u = tmp;
    }
    for (int i = l-1; i >= 0; i--) {
        if (d[dp[u][i]] - d[v] >= 0)
            u = dp[u][i];
    }
    if (v == u)
        return v;
    for (int i = l-1; i >= 0; i--) {
        if (dp[v][i] != dp[u][i]) {
            v = dp[v][i];
            u = dp[u][i];
        }
    }
    return p[v];
}

void input() {
    cin >> n;
    mas.resize(n);

    for (int i = 0; i < n; i++) {
        mas[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> mas[i][j];
        }
    }

}

int main() {
    input();
    prepairLCA();

    while (true) {
        cin >> u >> v;

        int ans = LCA(v, u);
        cout << ans << endl;
    }
    return 0;
}