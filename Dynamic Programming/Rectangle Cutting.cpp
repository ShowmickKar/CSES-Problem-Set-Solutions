/* Problem Link: https://cses.fi/problemset/task/1744/ */

#include <bits/stdc++.h>
using namespace std; 

const int inf = 1e9+7;
const int mxN = 501;

int dp[mxN][mxN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int a, b; 
	cin >> a >> b;
	for (int i = 1; i <= a; i++) {
		for (int j = 1; j <= b; j++) {
			if (i == j) {
				dp[i][j] = 0;				
			} else {
				dp[i][j] = inf;
				for (int k = 1; k < i; k++) {
					dp[i][j] = min(dp[i][j], dp[i - k][j] + dp[k][j] + 1);
				}
				for (int k = 1; k < j; k++) {
					dp[i][j] = min(dp[i][j], dp[i][j - k] + dp[i][k] + 1);
				}
			}
		}
	}
	cout << dp[a][b] << endl;
}
