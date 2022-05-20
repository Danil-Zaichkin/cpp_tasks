/*#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int n;
    cin >> n;

    int Pow = 2;
    double prev = 0;
    double cur = n;
    while (cur > prev) {
        prev = cur;
        cur = pow((double)n / Pow, Pow);
        Pow++;
    }
    Pow -= 2;

    int floor = n / Pow;
    int top = floor;
    if (n / (double)Pow - floor > 0.000000001) {
        top = floor+1;
    }

    unsigned long long res = 1;
    for(;Pow > 0; Pow--) {
        if (n - top < (Pow-1)*floor) {
            res *= floor;
            n -= floor;
        } else {
            res *= top;
            n -= top;
        }
    }
    cout << res;
    return 0;
}*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

const char check = '#';
const char uncheck = '.';
vector<string> mas;
int n,m;

struct point
{
    int x,y;
    point(){}
    point(int X, int Y)
    {
        x = X; y = Y;
    }
};

int moveX[4] = {-1, 0, 1, 0};
int moveY[4] = {0, -1, 0, 1};

bool correct(int x, int y)
{
    if (x < 0 || y < 0)
        return false;
    if (x >= n || y >= m)
        return false;
    return true;
}

void dfs(int fx, int fy)
{
    stack<point> s;
    s.push(point(fx, fy));
    while (!s.empty())
    {
        point cur = s.top();
        s.pop();
        for (int i = 0; i < 4; i++)
        {
            int x = cur.x + moveX[i];
            int y = cur.y + moveY[i];
            if (correct(x,y) && mas[x][y] == check)
            {
                mas[x][y] = uncheck;
                s.push(point(x, y));
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    mas.resize(n);
    for (int i = 0; i < n; i++)
        cin >> mas[i];
    int amount = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mas[i][j] == check)
            {
                dfs(i, j);
                amount++;
            }
        }
    }
    cout << amount;
    return 0;
}
