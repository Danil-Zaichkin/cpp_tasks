#include <iostream>
#include <vector>
using namespace std;

int main() {
    unsigned long long nAB, nBC, nAC;
    int n;
    cin >> n >> nAB >> nBC >> nAC;
    vector <unsigned long long> mas(6, 0);
    unsigned long long temp = min(min(nAB, nBC), nAC) /2;
    for (int i = 0; i < 6; i += 2)
        mas[i]=temp;
    nAB -= temp * 2; nBC -= temp * 2; nAC -= temp * 2, n -= temp * 3;
    n -= nAB + nBC + nAC;
    mas[1] = nAB; mas[3] = nBC; mas[5] = nAC;

    if (nAB == 0 && nBC == 0 && nAC == 0 && n==0) {
        cout << "YES" << endl;
        for (auto c : mas)
            cout << c << " ";
        return 0;
    }

    cout << "NO";
    return 0;
}
