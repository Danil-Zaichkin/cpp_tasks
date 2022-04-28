#include <iostream>
#include <vector>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<vector<int>> mas(n, vector<int>(n));
    int k=1,j=0,s=1;
    while(j<n*n) {
        for (int i = s-1; i < n-(s-1); ++i) {
            mas[s-1][i] = k++;
            j++;
        }
        for (int i = s; i < n-(s-1); ++i) {
            mas[i][n - s] = k++;
            j++;
        }
        for (int i = n - (s+1); i >= s-1; i--) {
            mas[n - s][i] = k++;
            j++;
        }
        for (int i = n - (s+1); i >= s; i--) {
            mas[i][s-1] = k++;
            j++;
        }
        s++;
    }

    for (vector<int> i : mas) {
        for (int j : i) {
            cout << j << ' ';
        }
        cout << endl;
    }

    return 0;
}
