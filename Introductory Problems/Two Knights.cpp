Proble link: https://cses.fi/problemset/task/1072/
Solution Idea: https://math.stackexchange.com/questions/3266257/number-of-ways-two-knights-can-be-placed-such-that-they-dont-attack/3266324#3266324

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll n;
	scanf("%lld", &n);
	for (ll i = 1; i <= n; ++i) {
		ll ans = (((i*i)*((i*i) - 1))/2 - 4*(i - 1)*(i - 2));
		printf("%lld\n", ans);
	}
}
