#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Student {
    int age;
    string name;
    string drink;
};

bool isprime(int num) {
    for (int i = 2; i < sqrt(num); i++) {
        if(num % i == 0)
            return false;
    }
    return true;
}

int main() {
    int num;
    cin >> num;
    Student* mas = new Student[num];

    for (int i = 0; i < num; i++) {
        cin >> mas[i].age >> mas[i].name >> mas[i].drink;
    }

    for (int i = 0; i < num; i++) {
        if (isprime(mas[i].age))
            cout << mas[i].name << ' ' << mas[i].drink << endl;
    }
}
