#include <fstream>
#include <iostream>

using namespace std;

int Min(int a, int b) {
    if (a < b)
        return a;
    else
        return b;
}

int main()
{
    ifstream fileIn("INPUT.TXT");
    ofstream fileOut("OUTPUT.TXT");

    int x = 0;
    int y = 0;
    int z = 0;
    
    int n, tmp;
    char symbol;
    fileIn >> n;
    for (int i = 0; i < n; i++) {
        fileIn >> symbol;
        if (symbol == 'X') {
            fileIn >> tmp;
            x += tmp;
        }
        else if (symbol == 'Y') {
            fileIn >> tmp;
            x += tmp;
            z += tmp;
        }
        else {
            fileIn >> tmp;
            z += tmp;
        }
    }
    if ((x > 0) and (z > 0))
        y = Min(x, z);
    if ((x < 0) and (z < 0))
        y = Min(x, z);
    x -= y;
    z -= y;
    fileOut << x + y + z;
    return 0;
}
