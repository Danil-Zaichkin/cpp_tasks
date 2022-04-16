#include <iostream>
#include <queue>

using namespace std;

int n;
int d, a;
int ans = 0;
bool* visited = new bool[n];
char** mas1 = new char* [n];
char** mas2 = new char* [n];

void get_graph_frame(char** input, char** output, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			if (input[i][j] == '1' and visited[j]) {

				output[i][j] = 'd';
				output[j][i] = 'd';
				ans += d;
			}
			else if (input[i][j] == '1' and !visited[j]) {
				visited[j] = true;
			}
		}
	}
}
void bfs(queue<int> que, char** mas, int start) {
	que.push(start);
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
}
void print(char** mas, int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << mas[i][j];
		}
		cout << endl;
	}
}

int main() {
	cin >> n;
	cin >> d >> a;
	
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

	get_graph_frame(mas1, mas2, n);

	fill(visited, visited + n, false);

	queue<int> que;
	int prev = -1;
	que.push(0);
	for (int j = 0; j < n; j++) {
		if (!visited[j]) {
			bfs(que, mas2, j);
			if (prev >= 0) {
				mas2[prev][j] = 'a';
				mas2[j][prev] = 'a';
				ans += a;
			}
			prev = j;
		}
	}
	cout << ans << endl;
	print(mas2, n);
}

