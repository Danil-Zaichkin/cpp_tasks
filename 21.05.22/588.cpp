#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n == 1 || n == 2 || n == 3 || n == 6) {
        cout << -1;
        return 0;
    }
    if (n == 4) {
        cout << 2 << endl << 1 << endl << 0 << endl << 1;
        return 0;
    }
    if (n == 5) {
        cout << 1 << endl << 2 << endl << 0 << endl << 0 << endl << 2;
        return 0;
    }
    vector<int> mas(n);
    mas[0] = 2;
    mas[1] = 1;
    mas[n - 5] = 1;
    mas[n-1] = n - 4;
    for (int i : mas)
        cout << i << endl;
    return 0;
}
