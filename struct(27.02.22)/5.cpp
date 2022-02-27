#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    string value;
    int wins = 0;
};

int game(string value1, string value2) {
    if (value1 == "stone"){
        if (value2 == "scissors") return 1;
        if (value2 == "paper") return 0;
    }

    if (value1 == "scissors"){
        if (value2 == "stone") return 0;
        if (value2 == "paper") return 1;
    }

    if (value1 == "paper"){
        if (value2 == "scissors") return 0;
        if (value2 == "stone") return 1;
    }

    return 0;
}

int main() {
    int num;
    cin >> num;
    Student* mas = new Student[num];

    for (int i = 0; i < num; i++) {
        cin >> mas[i].name >> mas[i].value;
    }

    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (i == j) continue;
            else {
                mas[i].wins += game(mas[i].value, mas[j].value);
                mas[i].wins += game(mas[i].value, mas[j].value);
            }
        }
    }
    int max_win = 0;
    string win_name;
    for (int i = 0; i < num; i++) {
        if (mas[i].wins > max_win) {
            max_win = mas[i].wins;
            win_name = mas[i].name;
        }
    }
    cout << win_name;
    return 0;
}
