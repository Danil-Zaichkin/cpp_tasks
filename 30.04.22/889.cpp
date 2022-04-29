#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    int k, m;
    cin >> k >> m;
    vector<pair<int, int>> mas(m);

    for (int i = 0; i < m; i++) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        mas[i] = {tmp2, tmp1};
    }

    sort(mas.begin(), mas.end());
    reverse(mas.begin(), mas.end());


    for (auto i : mas) {
        if (i.second == k) {
            k = i.second + 1;
        }
         else if (i.second == k-1) {
            k = i.second;
            
        }
    }
    cout << endl << k;
    return 0;
}
