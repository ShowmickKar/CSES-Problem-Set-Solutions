/* Problem Link: https://cses.fi/problemset/task/1633/ */

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

const int mx = 10e6 + 7;
int dp[mx];

void solve() {  
    int n; cin >> n; 
    dp[0] = 1; 
    for (int i = 1; i <= n; i++) {
    	for (int j = 1; j <= min(6, i); j++) {
    		(dp[i] += dp[i - j]) %= MOD;
    	}
    }
    cout << dp[n] << endl;
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    // int t; cin >> t;
    // while(t--) {
        solve();
    // }
}  
