#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

int main()
{
    ifstream fileIn("INPUT.TXT");
    ofstream fileOut("OUTPUT.TXT");

    int n, x, y;
    fileIn >> n >> x >> y;
    int ans = 0;
    if (x > y) {
        swap(x, y);
    }
    ans += x;
    n--;
    int left = 0;
    int right = y * n;
    while (left != right) {
        int sum = (left + right) / 2;
        if (sum / x + sum / y < n) {
            left = sum + 1;
        }
        else {
            right = sum;
        }
    }
    ans += left;
    fileOut << ans;
    return 0;
}
