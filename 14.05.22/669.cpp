#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

void f(int n) {
    int t = n;
    int ns[4] = { 0, 0, 0, 0 };
    int idx[4] = { 2, 3, 5, 7 };
    for (int i = 0; i < 4; i++) {
        while (n % idx[i] == 0) {
            n /= idx[i];
            ns[i]++;
        }
    }
    if (n > 1) {
        cout << -1 << ' ' << -1 << endl;
        return;
    }
    string max = "";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < ns[i]; j++)
            max = (char)(idx[i] + 48) + max;
    }

    string min = "";
    vector<int> mas;
    for (int i = 2; i < 4; i++) {
        for (int j = 0; j < ns[i]; j++)
            mas.push_back(idx[i]);
    }

    for (int i = 0; i < ns[0] / 3; i++)
        mas.push_back(8);

    for (int i = 0; i < ns[1] / 2; i++)
        mas.push_back(9);

    ns[0] %= 3;
    ns[1] %= 2;

    if (ns[0] == 2 and ns[1] == 1) {
        mas.push_back(6);
        ns[0] -= 1;
        ns[1] -= 1;
    }
    else if (ns[0] == 2 and ns[1] == 0) {
        mas.push_back(4);
        ns[0] -= 2;
    }

    if (ns[0] == 1 and ns[1] == 1)
        mas.push_back(6);
    else if (ns[0] == 1)
        mas.push_back(2);
    else if (ns[1] == 1)
        mas.push_back(3);

    sort(mas.begin(), mas.end());

    for (auto i : mas)
        min += (char)(i + 48);

    cout << min << ' ' << max << endl;
}

int main()
{
    int n = 1000;
    cin >> n;
    
    
        f(n);

    return 0;
}
