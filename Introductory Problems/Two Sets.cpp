Problem link: https://cses.fi/problemset/result/908971/

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

ll total;

vector<int> first_pair, used(1000007);

void solve() {	
	ll n, c; cin >> n;
	total = n*(n + 1)/2;
	if (total&1) {
		cout << "NO\n";
		return;
	}
	total /= 2;
	c = n;
	while(total > 0) {
		if (c <= total) {
			first_pair.push_back(c);
			used[c] = 1;
			total -= c;
			--c;
		}
		else {
			--c;
		}
	}
	cout << "YES\n";
	_reverse(first_pair);
	cout << first_pair.size() << endl;
	for (auto &u : first_pair) cout << u << " "; cout << endl;
	cout << n - first_pair.size() << endl;
	for (int i = 1; i <= n; ++i) {
		if (!used[i]) {
			cout << i << " ";
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
