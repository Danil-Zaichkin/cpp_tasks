#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int height;
    сin >> height;
    vector<int>count(height + 1, 0);
    count[0] = 1;
    int max_height = 1000 * 1000;
    for(int i=1; i <= height; ++i) {
        if (i >= 10)
            count[i] += count[i - 10];
        if (i >= 11)
            count[i] += count[i - 11];
        if (i >= 12)
            count[i] += count[i - 12];
        count[i] %= max_height;
    }
    cout << count[height] * 2 % max_height;
    return 0;
}