#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, h1, m1, h2, m2;
    int res = 0;
    cin >> n;

    vector<int> mas(1440);

    for (int i = 0; i < n; ++i) {
        cin >> h1 >> m1 >> h2 >> m2;
        int t1 = h1 * 60 + m1;
        int t2 = h2 * 60 + m2;

        if (t1 >= t2) {

            for (int j = t1; j < 1440; ++j)
                mas[j]++;
            for (int j = 0; j < t2; ++j)
                mas[j]++;
        }
        else
            for (int j = t1; j < t2; ++j)
                mas[j]++;
    }

    for (auto i : mas)
        if (i == n)
            res++;
    cout << res;
    return 0;
}
