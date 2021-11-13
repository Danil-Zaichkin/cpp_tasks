#include <iostream>;
#include <fstream>;
#include <string>;

using namespace std;

int main() {
	string fileName = "bus.dat";
	ifstream file(fileName);

	if (!file) {
		cout << "error opening file" << endl;
		return 0;
	}

	int tmp = 0;

	string str;
	while (!file.eof()) {
		getline(file, str);
		tmp++;
	}
	file.close();
	
	ifstream file_1(fileName);
	
	string** bus_data = new string* [tmp];
	for (int i = 0; i < tmp; i++) {
		bus_data[i] = new string[6];
		for (int j = 0; j < 6; j++) {
			file_1 >> bus_data[i][j];
			cout << bus_data[i][j] << " ";
		}
		cout << endl;
	}
	file_1.close();	
	
	string request;
	cin >> request;
	bool flag = false;
	
	if (request == "bus_count") {
		int bus_count = 0;
		for (int i = 0; i < tmp; ++i) {
			string str = bus_data[i][4];
			const char* c_str = str.c_str();
			bus_count += atoi(c_str);
		}
		cout << bus_count << endl;
	}
	else if (request == "route_by_number") {
		string number;
		cin >> number;
		for (int i = 0; i < tmp; i++) {
			if (bus_data[i][0] == number) {
				cout << bus_data[i][1] << " - " << bus_data[i][2] << endl;
				flag = true;
			}
		}
		if (!flag)
			cout << "not found" << endl;
	}
	else if (request == "numbers_by_point") {
		string point;
		cin >> point;
		for (int i = 0; i < tmp; i++) {
			if (bus_data[i][1] == point || bus_data[i][2] == point) {
				cout << bus_data[i][0] << ' ';
				flag = true;
			}
		}
		if (!flag)
			cout << "not found" << endl;
	}
	else if (request == "numbers_by_base") {
		string base;
		cin >> base;
		for (int i = 0; i < tmp; i++) {
			if (bus_data[i][5] == base) {
				cout << bus_data[i][0] << ' ';
				flag = true;
			}
		}
		if (!flag)
			cout << "not found" << endl;
	}

	return 0;
}
