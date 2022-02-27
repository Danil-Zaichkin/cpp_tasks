#include <iostream>
#include <string>

using namespace std;

struct Student {
    int age;
    string name;
    string drink;
};

int main() {
    int num;
    cin >> num;
    Student* mas = new Student[num];

    for (int i = 0; i < num; i++) {
        cin >> mas[i].age >> mas[i].name >> mas[i].drink;
    }

    for (int i = 0; i < num; i++) {
        cout << mas[i].age << ' ' << mas[i].name << ' ' << mas[i].drink << endl;
    }
}
