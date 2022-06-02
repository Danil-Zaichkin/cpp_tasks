#include <iostream>
#include <vector>

using namespace std;

int k = -1;
vector<vector<int>> mas;
vector<bool> visited;
int n, s;

void dfs(int v) {
    k++;
    visited[v] = true;
    for (int i = 0; i < n; i++) {
        if (mas[v][i] == 1 and !visited[i])
            dfs(i);
    }
}

int main() {

    cin >> n >> s;
    mas.resize(n);
    for (int i = 0; i < n;i ++) {
        mas[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> mas[i][j];
        }
    }
    visited.resize(n);
    fill(visited.begin(), visited.end(), false);

    dfs(s-1);
    cout << k << endl;

    return 0;
}