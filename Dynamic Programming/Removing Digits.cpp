/* Problem Link: https://cses.fi/problemset/task/1637/ */

#include <bits/stdc++.h>
#define INF 1e18
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
#define endl "\n";
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

vector<int> read_array(int n) {vector<int>a(n); for(int i=0; i<n;i++) cin>>a[i]; return a;}
vector<ll> read_array(ll n) {vector<ll>a(n); for(int i=0; i<n;i++) cin>>a[i]; return a;}
vector<pair<int,int>> read_pair(int n) {vector<pair<int, int>>a(n); for(int i=0; i<n; i++) {cin>>a[i].first>>a[i].second;} return a;}
void write_array(vector<int>a) {for(auto &u:a) cout<<u<< " "; cout<<endl;}

int calculate_highest_digit(int n) {
	int temp = n, ans = 0;
	while (temp > 0) {
		int digit = temp % 10;
		ans = max(ans, digit);
		temp /= 10;
	}
	return ans;
}

void solve() {  
	int n, ans = 0; cin >> n; 
	while (n) {
		n -= calculate_highest_digit(n);
		ans++;
	}
    cout << ans << endl;
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}  
