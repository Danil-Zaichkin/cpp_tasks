#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream fileIn("INPUT.TXT");
    ofstream fileOut("OUTPUT.TXT");
    int n;
    fileIn >> n;

    if (!fileIn) {
        return 0;
    }
    
    int* num = new int[n];
    int* len = new int[n]();

    for (int i = 0; i < n; ++i)
        fileIn >> num[i];

    int maxLen = -1;
    for (int i = 0; i < n; ++i) {
        for (int j = i - 1; j >= 0; --j)
            if (num[i] > num[j] and len[j] > len[i])
                len[i] = len[j];
        ++len[i];
        maxLen = max(maxLen, len[i]);
    }
    fileOut << maxLen;

    return 0;
}
