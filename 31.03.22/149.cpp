#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream fileIn("input.txt");
	ofstream fileOut("output.txt");
	int n;
	int num[3];

	fileIn >> n;
	for (int i = 0; i < n; i++) {
		fileIn >> num[i];
	}
	
	for (int i = n - 1; i >= 0; i--)
		fileOut << num[i] << ' ';
}
