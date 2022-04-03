#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main()
{

	ifstream fileIn("input.txt");
	ofstream fileOut("output.txt");
	int n, d;
	fileIn >> n >> d;
	vector<int> vec;
	map<int, int> dict;
	vector<int> res;
	for (int i = 0; i < n; i++) {
		int a;
		fileIn >> a;
		vec.push_back(a);
		dict[a] = 0;
		res.push_back(a);
	}
	sort(vec.begin(), vec.end(), greater<int>());
	int max = -9999999;
	int k = 0;
	for (int i = 0; i < vec.size() - 1; i++) {
		for (int j = i; j < vec.size(); j++) {
			if (vec[i] - vec[j] <= d) {
				k++;
			}
		}
		if (k > max)
			max = k;
		k = 0;
	}
	fileOut << max << endl;

	int c = 1;
	for (int i = 0; i < vec.size(); i++) {
		if (c > max)
			c = 1;
		dict[vec[i]] = c;
		c++;
	}

	for (int i = 0; i < vec.size(); i++) {
		fileOut << dict[res[i]] << " ";
	}
}
