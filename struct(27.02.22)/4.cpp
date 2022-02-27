#include <iostream>
#include <string>

using namespace std;

struct Student {
    int age;
    string name;
    string drink;
};

void sort(string *name, int n){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n-i-1; ++j) {
            if (name[j] > name[j + 1]) {
                swap(name[j], name[j + 1]);
            }
        }
    }
}

int main() {
    int num;
    cin >> num;
    Student* mas = new Student[num];

    for (int i = 0; i < num; i++) {
        cin >> mas[i].age >> mas[i].name >> mas[i].drink;
    }

    string* name = new string[num];

    for (int i = 0; i < num; i++) {
        string name1;
        string name2 = mas[i].name;
        for (int j = name2.size(); j >= 0; j--) {
            name1 += name2[j];
        }
        name[i] = name1;
    }
    
    sort(name, num);

    for (int i = 0; i < num; i++) {
        cout << name[i] << ' ';
    }
    return 0;
}
