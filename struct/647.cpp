#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int* mas = new int[n];

    for (int i = 0; i < n; i++) {
        mas[i] = i + 1;
    }

    int m;
    cin >> m;
    int* digit = new int[m];

    for (int i = 0; i < m; i++) {
        cin >> digit[i];
    }

    for (int i = 0; i < m; i++) {
        int tmp = 0;
        int tmp_value = mas[0];
        int tmp_value1 = 0;

        for (int j = 0; j < n; j++) {
            if (mas[j] != digit[i]) {
                tmp++;
                if (tmp > 0) {
                    tmp_value1 = mas[j];
                    mas[j] = tmp_value;
                    tmp_value = tmp_value1;
                }
            } else {
                mas[0] = digit[i];
                mas[j] = tmp_value;

                break;
            }
        }
        cout << tmp+1 << " ";

    }
}
