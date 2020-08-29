Problem link: https://cses.fi/problemset/task/1084

#include <bits/stdc++.h>
#define INF 1e18
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

int n, m, k, p, q, t, ans = 0;

void solve() {
	cin >> n >> m >> k;
	vector<int> a(n), b(m), free(m);
	for (int i = 0; i < n; ++i) cin >> a[i];
	for (int i = 0; i < m; ++i) cin >> b[i];
	_sort(a);
	_sort(b);
	for (int i = 0, j = 0; i < n; ++i) {
		while(j < m && b[j] < a[i] - k) ++j;
		if (j < m && b[j] <= a[i] + k) {
			++ans;
			++j;
		}
	}
	cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--)
        solve();
}
