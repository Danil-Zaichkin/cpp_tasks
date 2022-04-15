#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fileIn("input.txt");
    ofstream fileOut("output.txt");
    int n;
    fileIn >> n;
    long long x = (n * n + 1) / 2;
    fileOut << (x - 1) / 9 * 10 + (x - 1) % 9 + 1;
    return 0;
}
