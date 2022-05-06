#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> road(n);
    int di, li, hi;
    int roadLength = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> di >> li >> hi;
        road[i] = pair<int, int>(min(li, m), hi);
        roadLength += di;
    }
    sort(road.begin(), road.end());

    int speed = road[0].first;
    int amountH = 0;
    double minTime = numeric_limits<int32_t>::max();
    for(auto segment : road)
    {
        if (1.0 * roadLength / segment.first + amountH <= minTime)
        {
            minTime = 1.0 * roadLength / segment.first + amountH;
            speed = segment.first;
        }
        amountH += segment.second;
    }
    cout << speed << endl;
}
