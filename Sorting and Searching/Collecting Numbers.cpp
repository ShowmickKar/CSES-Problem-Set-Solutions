// Problem Link: https://cses.fi/problemset/task/2216/

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

template<typename T>
vector<T> read(T n) {vector<T>a(n); for(int i=0; i<n;i++) cin>>a[i]; return a;}
vector<string> read_string(int n) {vector<string>grid(n);for (auto &u:grid) cin>>u; return grid;}
template<typename T>
void write(vector<T>a) {for(auto &u:a) cout<<u<< " "; cout<<endl;}

void solve() {  
   int n, ans = 0; cin >> n;
   vector<int> a = read(n);
   unordered_map<int, int> m;
   for (int i = 0; i < n; i++) {
       m[a[i]] = i;       
   }
   for (int i = 1; i < n; i++) {
   	   if (m[i] > m[i + 1]) ans++;
   }
   cout << ++ans << endl;
}   

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solve();
}  
