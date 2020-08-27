Problem link: https://cses.fi/problemset/task/1755/

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

int cnt = 0, c;
char odd;

void solve() {	
	string s; cin >> s;
	map<char, int> m;
	for (auto &u : s) ++m[u];
	for (auto &u : m) {
		if (u.second&1) {
			odd = u.first;
			c = u.second;
			++cnt;
		}
		if (cnt > 1) {
			cout << "NO SOLUTION\n";
			return;
		}
	}
	for (auto &u : m) {
		if (u.first == odd) continue;
		for (int i = 0; i < u.second/2; ++i) {
			cout << u.first;
		}
	}
	for (int i = 0; i < c; ++i) cout << odd;
	for (auto u = m.rbegin(); u != m.rend(); ++u) {
		if (u->first == odd) continue;
		for (int i = 0; i < u->second/2; ++i) {
			cout << u->first;
		}
	}
	cout << endl;
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    // int t; cin >> t;
    // while(t--) 
        solve();
}
