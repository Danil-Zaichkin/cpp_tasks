#include <algorithm>
#include <fstream>
#include <vector>
#include <cstdio>
using namespace std;

int main()
{
    FILE* fileIn = fopen("input.txt", "r");
    ofstream fileOut("output.txt");
    int n;
    fscanf(fileIn, "%d", &n);
    vector<vector<int>>vec(n, vector<int>(3));
    for (int i = 0; i < n; ++i)
        fscanf(fileIn, "%d:%d:%d", &vec[i][0], &vec[i][1], &vec[i][2]);
    sort(vec.begin(), vec.end());
    fileOut << vec[n / 2 - 1][0] << ":";
    if (vec[n / 2 - 1][1] < 10)
        fileOut << 0 << vec[n / 2 - 1][1] << ":";
    else
        fileOut << vec[n / 2 - 1][1] << ":";
    if (vec[n / 2 - 1][2] < 10)
        fileOut << 0 << vec[n / 2 - 1][2];
    else
        fileOut << vec[n / 2 - 1][2];
    return 0;
}