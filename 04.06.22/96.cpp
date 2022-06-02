#include <iostream>
#include <vector>

using namespace std;

int got = 0;
int moveX[4] {1, 0, -1, 0 };
int moveY[4] {0, 1, 0, -1 };
int dx = moveX[0], dy = moveY[0];

int main()
{
    int n, m;
    cin >> n >> m;
    if (n * m == 0){
        cout << 0;
        return 0;
    }
    vector<vector<int>> mas;
    mas.resize(n + 2);
    for (int i = 0; i <= n + 1; i++){
        mas[i].resize(m + 2);
        for (int j = 0; j <= m + 1; j++){
            if (i == 0 or i == n + 1 or j == 0 or j == m + 1)
                mas[i][j] = 0;
            else
                mas[i][j] = 1;
        }
    }

    int x, y;
    cin >> y >> x;
    mas[y][x] = 2;
    x = 1; y = 1;
    int ans = 0;
    while (mas[y][x] != 2){
        if (mas[y][x] == 0){
            x = x - dx; y = y - dy;
            got = (got + 5) % 4;
            dx = moveX[got]; dy = moveY[got];
            x = x + dx; y = y + dy;
        }
        if (mas[y][x] != 2){
            ans++;
            mas[y][x] = 0;
            x = x + dx;
            y = y + dy;
        }
    }
    ans++;
    cout << ans << endl;
    return 0;
}