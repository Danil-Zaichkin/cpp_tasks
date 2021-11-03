#include <iostream>
#include <string>
using namespace std;
 
int main()
{
    string inputString, resultString;
    getline(cin, inputString);
    int i;
    for (i = 0; i < inputString.size(); i++) {
        if (inputString[i] <= '9' && inputString[i] >= '0')
            resultString += inputString[i];
    }
    cout << resultString;
}
