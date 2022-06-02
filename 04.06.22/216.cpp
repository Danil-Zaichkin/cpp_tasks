#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int sum = 0;
    cin >> n;
    vector<int> mas(n);
    for (int i = 0; i < n; i++){
        cin >> mas[i];
        sum += mas[i];
    }
    sort(mas.begin(), mas.end());
    int masMax = mas[n - 1];
    int masMin = min(sum / 2, sum - masMax);
    cout << masMin;
    return 0;
}