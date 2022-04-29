#include <iostream>
#include <string>

using namespace std;

int IndexOf(string dataString, char ch)
{
    int k = dataString.length() - 1;
    while (k > -1)
    {
        if (dataString[k] == ch)
            return k;
        --k;
    }
    return -1;
}

void SearchBMHSubstring(string dataString, string templateString)
{
    int n = dataString.length();
    int m = templateString.length();
    
    if (n == 0 || m == 0) {
        cout << -1;
        return;
    }
    
    int* pIndex = new int[m];

    for (int i = 0; i < m; ++i)
    {
        char ch = templateString[i];
        int length = m - i - 1;
        pIndex[i] = length;
    }
    pIndex[m - 1] = templateString.length();

    int i = m - 1;

    int j = i;
    int k = i;

    while (i < n)
    {
        k = i;
        j = m - 1;

        while (j > -1 && dataString[k] == templateString[j])
        {
            k--;
            j--;
        }

        if (j == -1)
            cout << k + 1;

        char currentChar = dataString[i];
        int index = IndexOf(templateString, currentChar);
        if (index == -1)
            index = m - 1;

        i += pIndex[index];
    }
}

int main() {

    string str;
    string substr;
    getline(cin, str);
    getline(cin, substr);

    SearchBMHSubstring(str, substr);
}
