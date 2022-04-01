#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream fileIn("input.txt");
	ofstream fileOut("output.txt");
    int n;
    fileIn >> n;
    int b = n % 3;
    n /= 3;
    switch (n)
    {
    case 0:
        fileOut << "Winter";
        break;
    case 1:
        fileOut << "Spring";
        break;
    case 2:
        fileOut << "Summer";
        break;
    case 3:
        fileOut << "Autumn";
        break;
    case 4:
        if (b == 0)
            fileOut << "Winter";
        else
            fileOut << "Error";
        break;
    default:
        fileOut << "Error";
        break;
    }
