#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    ifstream fileIn("INPUT.txt");
    ofstream fileOut("OUTPUT.TXT");
    long long n;
    fileIn >> n;

    vector<long long> vec(n);
    for (int i = 0; i < n; ++i)
        fileIn >> vec[i];

    sort(vec.begin(), vec.end());
    long long num1, num2;
    num1 = vec[n - 1] * vec[n - 2] * vec[n - 3];
    num2 = vec[n - 1] * vec[0] * vec[1];

    fileOut << max(num1, num2);

    return 0;
}
