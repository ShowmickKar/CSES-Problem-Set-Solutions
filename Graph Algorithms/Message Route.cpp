Problem link: https://cses.fi/problemset/task/1667/

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
vector<int> dist(100007), pred(100007, -1);
queue<int> q;

void bfs(int x) {
	dist[x] = 1;
	visited[x] = true;
	q.push(x);
	while (!q.empty()) {
		int s = q.front();
		q.pop();
		for (auto &u : adj[s]) {
			if (visited[u]) continue;
			dist[u] = dist[s] + 1;
			pred[u] = s;
			visited[u] = true;
			q.push(u);
 		}
	}
}

void solve() {	
	int n, m; cin >> n >> m;
	vector<int> path;
	for (int i = 0; i < m; ++i) {
		int x, y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	bfs(1);
	if (!visited[n]) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	int current_node = n;
	while(current_node != 1) {
		path.push_back(current_node);
		current_node = pred[current_node];
	}
	path.push_back(1);
	_reverse(path);
	cout << dist[n] << endl;
	for (auto &u : path) cout << u << " "; cout << endl; 
}   
 
int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
 
    // int t; cin >> t;
    // while(t--) 
        solve();
}
