#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<long long> count(n + 1), sum(n + 1);
    count[0] = 1;
    sum[0] = 1;
    if (n % 2 == 1){
        cout << 0;
        return 0;
    }
    for (int i = 2; i <= n; i++){
        count[i] = count[i - 2] + 2 * sum[i - 2];
        sum[i] = sum[i - 2] + count[i];
    }
    cout << count[n];
    return 0;
}