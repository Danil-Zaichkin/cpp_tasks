#include <iostream>
#include <map>
#include <string>
#include <cctype>

using namespace std;

int main()
{

    map<string, int> dict;
    int n, m;
    cin >> n >> m;
    string tmp;
    getline(cin, tmp);
    for (int i = 0; i < n; i++) {
        getline(cin, tmp);
        dict[tmp] = 1;
    }
    bool flag = false;
    for (int i = 0; i < m; i++) {
        tmp = "";
        string str;
        getline(cin, str);
        for (auto j : str) {
            if (isalpha(j)) {
                tmp += tolower(j);
            } else if (tmp.size()) {
                if (dict.count(tmp))
                    dict[tmp] = 2;
                else {
                    flag = true;
                }
                tmp = "";
            }
        }
        if (tmp.size())
            if (dict.count(tmp))
                dict[tmp] = 2;
            else {
                flag = true;
            }
    }
    if (flag) {
        cout << "Some words from the text are unknown.";
        return 0;
    }

    for (auto i : dict) {
        if (i.second == 1 ) {
            cout << "The usage of the vocabulary is not perfect.";
            return 0;
        }
    }
    cout << "Everything is going to be OK.";
    return 0;
}
