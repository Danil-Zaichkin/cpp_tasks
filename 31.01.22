#include <fstream>
#include <iostream>

using namespace std;

int main() {
	ifstream fileIn("input.txt");
	ofstream fileOut("output.txt");
	int num[3];
	int sum = 0;
	int max = 0;

	for (int i = 0; i < 3; i++) {
		fileIn >> num[i];
		sum += num[i];
		if (num[i] > max)
			max = num[i];
	}
	fileOut << (sum - max == max ? "YES": "NO");
}
