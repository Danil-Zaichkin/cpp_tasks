#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

int main() {
    ifstream fileIn("INPUT.TXT");
    ofstream fileOut("OUTPUT.TXT");

    vector<int> vec;
    int tmp;
    while (!fileIn.eof()) {
        fileIn >> tmp;
        vec.push_back(tmp);
    }

    sort(vec.begin(), vec.end());

    int d = vec[1] - vec[0];
    for (int i = 1; i < vec.size() - 1; ++i) {
        if (vec[i + 1] - vec[i] != d) {
            fileOut << "No";
            return 0;
        }
    }
    fileOut << "Yes";
    return 0;
}
