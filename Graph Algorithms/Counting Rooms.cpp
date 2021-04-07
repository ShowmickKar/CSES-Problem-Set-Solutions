/* Problem Link: https://cses.fi/problemset/task/1192/ */

#include <bits/stdc++.h>
using namespace std;

vector<vector<bool>> visited(1001, vector<bool>(1001));
vector<vector<char>> grid(1001, vector<char>(1001));

int n, m, counter = 0;

void traverse(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= m || visited[i][j] || grid[i][j] == '#') {
		return;
	}
	visited[i][j] = true;
	traverse(i + 1, j);
	traverse(i - 1, j);
	traverse(i, j + 1);
	traverse(i, j - 1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			grid[i][j] = a[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (grid[i][j] == '.' && !visited[i][j]) {
				traverse(i, j);
				counter++;
			}	
		}
	}

	cout << counter << endl;
}
