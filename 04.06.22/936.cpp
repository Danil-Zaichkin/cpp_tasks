#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

struct Point{
    int x;
    int y;
};

int main()
{

    int mX, mY, n;
    double r;
    cin >> mX >> mY >> r >> n;
    vector<Point> pointMas;
    for (int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x -= mX;
        y -= mY;
        if (sqrt(x * x + y * y) <= r)
            pointMas.push_back(Point{x, y });
    }
    int ans = 0;
    for (Point p1 : pointMas){
        int on = 0, left = 0, right = 0;
        for (auto p2 : pointMas){
            int cp = p1.x * p2.y - p2.x * p1.y;
            if (cp < 0){
                left++;
            }
            else if (cp > 0){
                right++;
            }
            else
                on++;
        }
        ans = max({ans, on + left, on + right});
    }
    cout << ans;
    return 0;
}