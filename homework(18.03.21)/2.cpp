#include <iostream>
#include <list>
#include <random>

using namespace std;

int main() {
    list <int> num;

    for (int i = 0; i < 10000; i++) {
        num.push_back(rand());
    }
    int sum = 0;
    for (int i : num) {
        sum += i;
    }
    cout << sum / 10000;
    return 0;
}
