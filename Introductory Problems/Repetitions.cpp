Prblem link: https://cses.fi/problemset/task/1069/

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
	int temp = 1, cnt = 1; 
	string s; cin >> s;
	for (int i = 0; i < s.length() - 1; ++i) {
		if (s[i] == s[i + 1]) {
			++temp;
		}
		else temp = 1;
		cnt = max(temp, cnt);
	}
	cout << cnt << endl;
}   

int main() {
    ios::sync_with_stdio(0);
    cin.tie(nullptr);

    // int t; cin >> t;
    // while(t--) 
        solve();
}
