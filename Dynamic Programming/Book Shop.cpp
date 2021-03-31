/*Problem Link: https://cses.fi/problemset/task/1158/ */

#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio;
	cin.tie(nullptr);

	int n, target; cin >> n >> target; 
	vector<int> price(n), pages(n);
	for (int i = 0; i < n; i++) cin >> price[i];
	for (int i = 0; i < n; i++) cin >> pages[i];
	vector<vector<int>> dp(n + 1, vector<int>(target + 1));
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= target; j++) {
			dp[i][j] = dp[i - 1][j];
			int left = j - price[i - 1];
			if (left >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][left] + pages[i - 1]);
			}
		}
	}	
	cout << dp[n][target] << endl;;	
}
