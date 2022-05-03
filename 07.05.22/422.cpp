#include <iostream>
#include <vector>

using namespace std;

vector <pair<int, int>> mas;

void fareiSec(int, int, int, int, int);

void fareiSec(int n) {
    fareiSec(n, 0, 1, 1, 1);
}

void fareiSec(int n, int x, int y, int z, int t) {
    int a = x + z;
    int b = y + t;
    if (b <= n) {
        fareiSec(n, x, y, a, b);
        mas.push_back({a, b});
        fareiSec(n, a, b, z, t);
    }
}

int main() {
    int n;
    cin >> n;
    fareiSec(n);
    for (auto i : mas) {
        cout << i.first << '/' << i.second << endl;
    }
}
