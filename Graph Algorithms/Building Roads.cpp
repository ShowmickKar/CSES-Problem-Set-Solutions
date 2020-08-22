Problem link: https://cses.fi/problemset/task/1666/

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

vector<vector<int>> adj(100007);
vector<bool> visited(100007);

void dfs(int x) {
	visited[x] = true;
	for (auto &u : adj[x]) {
		if (visited[u]) continue;
		dfs(u);
	}
}

void solve() {	
	int n, m; cin >> n >> m;
	vector<int> connection;
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	for (int i = 1; i < n + 1; ++i) {
		if (visited[i]) continue;
		connection.push_back(i);
		dfs(i);
	}
	cout << connection.size() - 1 << endl;
	if (connection.size() > 1) {
		for (int i = 0; i < connection.size() - 1; ++i) {
			cout << connection[i] << " " << connection[i + 1] << endl;
		}
	}
}   
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    // int t; cin >> t;
    // while(t--) 
        solve();
}
