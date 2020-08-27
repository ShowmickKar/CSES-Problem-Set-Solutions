Problem link: https://cses.fi/problemset/task/1754/

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
	int a, b; cin >> a >> b;
	if (a > b) swap(a, b);
	if (b > 2 * a || (a + b) % 3 != 0) {
		cout << "NO\n";
	}
	else cout << "YES\n";
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--) 
        solve();
}
