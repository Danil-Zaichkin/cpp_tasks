#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int>>& mas, int start_point, int finish_point, int n) {
    vector<int> d(n, -1);
    d[start_point] = 0;
    queue<int> que;
    que.push(start_point);
    while(!que.empty()) {
        int cur = que.front();
        que.pop();
        for (int i = 0; i < n; i++) {
            if (mas[cur][i] == 1 and d[i] == -1) {
                que.push(i);
                d[i] = d[cur] + 1;
            }
        }
    }

    cout << d[finish_point];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mas(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mas[i][j];
        }
    }
    int k, l;
    cin >> k >> l;

    bfs(mas, k-1, l-1, n);

}