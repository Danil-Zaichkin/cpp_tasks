#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream fileIn("input.txt");
	ofstream fileOut("output.txt");
	int num[3];
	for (int i = 0; i < 3; i++) {
		fileIn >> num[i];
	}

	num[1] + num[2] <= num[0] ? fileOut << "YES" : fileOut << "NO";
}
