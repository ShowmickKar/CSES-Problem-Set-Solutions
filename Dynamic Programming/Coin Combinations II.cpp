/* Problem Link: https://cses.fi/problemset/task/1636 */

#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

int main() {
	int n, target;
	cin >> n >> target;
	vector<int> coin(n);
	for (auto &c : coin) cin >> c;
	vector<vector<int>> dp(n + 1, vector<int> (target + 1, 0));
	dp[0][0] = 1; 
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= target; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - coin[i - 1] >= 0) {
				dp[i][j] += dp[i][j - coin[i - 1]];
				dp[i][j] %= mod;
			}
		}
	}
	cout << dp[n][target] << endl;
}
