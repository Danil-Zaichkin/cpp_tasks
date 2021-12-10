#include <iostream>

using namespace std;

int main() {
    int num;
    cin >> num;
    int *mas = new int[num];
    for (int i = 0; i < num; i++) {
        cin >> mas[i];
    }

    for (int i = 1; i < num+1; i++) {
        int first = 0;
        int last = 0;
        int j = 0;
        while (mas[j] != i){
            if (mas[j] > i)
                first += 1;
            ++j;
        }
        ++j;
        while (j < num) {
            if (mas[j] < i)
                last += 1;
            ++j;
        }
        cout << first + 1 << " " << num - last << endl;

    }
    return 0;
}
