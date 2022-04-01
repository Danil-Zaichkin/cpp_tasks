#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream fileIn("input.txt");
	ofstream fileOut("output.txt");
	vector <int> n(3);
	vector <int> m(3);

	for (int i = 0; i < 3; i++) {
		fileIn >> n[i];
	}
	for (int i = 0; i < 3; i++) {
		fileIn >> m[i];
	}

	int sum = 0;
	sort(n.begin(), n.end());
	sort(m.begin(), m.end ());

	for (int i = 0; i < 3; i++)
		sum += n[i] * m[i];
	fileOut << sum;
}
