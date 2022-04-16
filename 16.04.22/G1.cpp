#include <iostream>
#include <queue>

using namespace std;



int main() {
	int n;
	int d, a;
	int ans = 0;
	int flag = 0;
	cin >> n;
	cin >> d >> a;
	bool* visited = new bool[n];
	char** mas1 = new char* [n];
	char** mas2 = new char* [n];
	

	for (int i = 0; i < n; i++) {

		mas1[i] = new char[n];
		mas2[i] = new char[n];
		visited[i] = false;
		
		
		for (int j = 0; j < n; j++) {
			char tmp;
			cin >> tmp;
			mas1[i][j] = tmp;
			mas2[i][j] = '0';
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (mas1[i][j] == '1' and visited[j]) {

				mas2[i][j] = 'd';
				mas2[j][i] = 'd';
				ans += d;
			}
			else if (mas1[i][j] == '1' and !visited[j]) {
				visited[j] = true;
			}
		}
	}

	fill(visited, visited + n, false);

	queue<int> que;
	int prev = -1;
	que.push(0);
	for (int j = 0; j < n; j++) {
		if (!visited[j]) {
			que.push(j);
			while (!que.empty()) {
				int tmp = que.front();
				que.pop();
				if (visited[tmp]) {
					continue;
				}
				visited[tmp] = true;
				for (int i = 0; i < n; i++) {
					if (mas1[tmp][i] == '1') {
						que.push(i);
					}
				}
			}
			if (prev >= 0) {
				mas2[prev][j] = 'a';
				mas2[j][prev] = 'a';
				ans += a;
			}
			prev = j;
		}
	}
	
	cout << ans << endl;;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mas2[i][j];
		}
		cout << endl;
	}
}
