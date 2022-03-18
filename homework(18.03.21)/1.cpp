#include <iostream>
#include <fstream>
#include <list>

using namespace std;

int main() {
    string fileName = "input.txt";
    ifstream inputFile(fileName);

    if (!inputFile) {
        cout << "error!" << endl;
        return 1;
    }
    list <double> num;
    int k = 0;
    while (inputFile.eof()) {
        double tmp;
        inputFile >> tmp;
        num.push_back(tmp);
        k++;
    }
    num.sort();
    double sum = 0;
    for (double i : num) {
        sum += i;
    }
    cout << sum / k;
    return 0;
}
