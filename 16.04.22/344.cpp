#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ifstream fileIn("INPUT.TXT");
	ofstream fileOut("OUTPUT.TXT");

	int n;
	fileIn >> n;

	vector <pair<int, int>> vec;
	
	int tmp;
	for (int i = 0; i < n; i++) {
		fileIn >> tmp;
		vec.push_back(pair<int, int>{tmp, i+1});
	}
	sort(vec.begin(), vec.end());

	int min = abs(vec[0].first - vec[1].first);
	int num1 = vec[0].second;
	int num2 = vec[1].second;
	for (int i = 1; i < n - 1; i++) {
		if (abs(vec[i+1].first - vec[i].first) < min) {
			min = abs(vec[i].first - vec[i+1].first);
			num1 = vec[i].second;
			num2 = vec[i + 1].second;
		}
	}
	fileOut << min << endl << num1 << ' ' << num2;
	return 0;
}
