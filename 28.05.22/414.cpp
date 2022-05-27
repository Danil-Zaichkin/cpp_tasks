#include <vector>
#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int a, b;
    cin >> a;
    cin >> b;

    vector <int> mas;
    vector <int> mas1;
    vector <int> mas2;
    mas.push_back(1);
    mas.push_back(1);

    int k;
    for (int i = 1; i < n; ++i) {
        cin >> k;
        mas.push_back(k);
    }

    int x = a;
    mas1.push_back(x);
    int y = b;
    mas2.push_back(y);

    while (x != 1) {
        x = mas[x];
        mas1.push_back(x);
    }

    while (y != 1) {
        y = mas[y];
        mas2.push_back(y);
    }

    x = a;
    y = b;

    while (x != y) {
        if (mas2.size() > mas1.size())
            mas2.erase(mas2.begin());
        else
            mas1.erase(mas1.begin());
        x = mas1[0];
        y = mas2[0];
    }

    cout << x << endl;

    return 0;
}