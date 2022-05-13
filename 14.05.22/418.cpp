
#include <vector>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {

    int curr = 0;
    int mx = 0;

    string str;
    getline(cin, str);

    vector<int> mas;
    mas.push_back(0);

    for (char i : str) {
        if (i == '<') {
            if (mas[curr] > 0)
                mas[curr]--;
            else if (curr > 0)
                mas.erase(mas.begin() + curr--);
        } else if (i == '^') {
            if (curr > 0)
                curr--;
        } else if (i == '|') {
            if (curr + 1 < mas.size())
                ++curr;
        } else if (i == '\\') {
            mas.push_back(0);
            ++curr;
        } else {
            mas[curr]++;
        }
        mx = max(mx, mas[curr]);
    }

    cout << mx;

    return 0;
}
