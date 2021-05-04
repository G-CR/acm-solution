#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 1e9+7;
int n, m, k;
ll fac[2000006];
vector <pair <int, int> > g;

ll qpow(ll x, ll n) {
	ll res = 1;
	for(; n; n >>= 1, x = x * x % mod)
		if(n & 1) res = res * x % mod;
	return res;
}

ll inv(ll a) {
	return qpow(a, mod-2)%mod;
}

void solve() {
	fac[0] = 1;
	for(int i = 1;i < 2000006; i++) {
		fac[i] = (fac[i-1]*i)%mod;
	}
}

ll comb(ll n, ll k) {
	if(k > n) return 0;
	if(k == 1) return n;
	return (fac[n]*inv(fac[k])%mod * inv(fac[n-k])%mod);
}

int main() {
	solve();
	scanf("%d %d %d", &n, &m, &k);
	g.push_back({1, 1});
	for(int i = 1; i <= k; i++) {
		int x, y; scanf("%d %d", &x, &y);
		g.push_back({x, y});
	}
	g.push_back({n, m});
	
	ll ans = 1;
	for(int i = 1; i < g.size(); i++) {
		ll x = abs(g[i].first - g[i-1].first);
		ll y = abs(g[i].second - g[i-1].second);
		ans = (ans * comb(x+y, x)) % mod;
	}
	
	printf("%lld\n", ans);
}