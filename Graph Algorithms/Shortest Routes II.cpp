// Problem Link: https://cses.fi/problemset/task/1672/

#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n, m;

const int mxN = 503;
const ll inf = 1e18+7;
const ll mod = 1e18+7;

ll dp[mxN][mxN];

void floyd_warshall() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
 	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> n >> m >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) dp[i][j] = 0;
			else dp[i][j] = inf;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		ll c;
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
		dp[b][a] = min(dp[b][a], c);
	}
	floyd_warshall();
	while(q--) {
		int a, b;
		cin >> a >> b;
		cout << (dp[a][b] == inf ? -1 : dp[a][b]) << endl;
	}
}
