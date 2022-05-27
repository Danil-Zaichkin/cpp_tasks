#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct point {
    int x;
    int y;
    point() {}
    point(int ix, int iy) {
        x = ix;
        y = iy;
    }
};

bool correct_neighbor(int x, int y) {
    if (x < 0 or y < 0)
        return false;
    if (x >= n or y >= m)
        return false;
    return true;
}

void bfs(vector<vector<int>>& mas, int ix, int iy) {
    int offsetX[4] = { -1, 0, 1, 0 };
    int offsetY[4] = { 0, -1, 0, 1};
    queue<point> que;
    que.push(point(ix, iy));
    while(!que.empty()) {
            point cur = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {

                int x = cur.x + offsetX[i];
                int y = cur.y + offsetY[i];
                if (correct_neighbor(x, y) and mas[x][y] == 0) {
                    mas[x][y] = 1;
                    que.push(point(x, y));
                }
            }
    }
}

int main()
{
    cin >> n >> m;
    vector<vector<int>> mas(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mas[i][j];
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mas[i][j] == 0) {
                bfs(mas, i, j);
                ans++;
            }
        }
    }
    cout << ans;
}