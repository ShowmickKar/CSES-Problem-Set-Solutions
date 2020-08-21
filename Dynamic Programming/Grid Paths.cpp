Problem link: https://cses.fi/problemset/task/1638

#include <bits/stdc++.h>
#define INF 1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define arr array
#define _min(a) *min_element(a.begin(), a.end());
#define _max(a) *max_element(a.begin(), a.end());
#define _sort(x) sort(x.begin(), x.end())
#define _rsort(x) sort(x.rbegin(), x.rend())
#define _reverse(x) reverse(x.begin(), x.end())
#define _debug(x) cout << #x << " = " << x << endl;
#define debug(x, y) cout << #x " = " << x << " " << #y << " = " << y << endl;
#define _lower_bound(a, x) lower_bound(a.begin(), a.end(), x) - a.begin()
#define _upper_bound(a, x) upper_bound(a.begin(), a.end(), x) - a.begin()
typedef long long ll;
using namespace std;

void solve() {	
	int n; cin >> n;
	vector<string> a(n); for (auto &u : a) cin >> u;
	vector<vector<int>> dp(n, vector<int> (n, 0));
	dp[0][0] = (a[0][0] == '*' ? 0 : 1);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i) dp[i][j] += dp[i - 1][j];
			if (j) dp[i][j] += dp[i][j - 1];
			if (a[i][j] == '*') dp[i][j] = 0;
			dp[i][j] %= MOD;
		}
	}
	cout << dp[n - 1][n - 1] % MOD << endl;
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    // int t; cin >> t;
    // while(t--) 
        solve();
}
