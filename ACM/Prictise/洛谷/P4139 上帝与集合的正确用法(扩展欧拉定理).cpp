#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll phi(ll n) {
	ll ans = n;
	for(ll i = 2 ; i*i<=n ; i++ ) {
		if(!(n%i)){
			ans = ans/i*(i-1);
			while(n%i == 0 ) {
				n/=i ;
			}
		}
	}
	if(n>1) ans = ans/n*(n-1);
	return ans;
}

ll qpow(ll x, ll n, ll mod) {
	ll res = 1;
	for(; n; n >>= 1, x = x * x % mod)
		if(n & 1) res = res * x % mod;
	return res;
}

ll dfs(ll fip) {
	if(fip == 1) return 1;
	return qpow(2ll, dfs(phi(fip)), fip) % fip + fip;
}

int main() {
	int _; scanf("%d", &_);
	while(_--) {
		ll p; scanf("%lld", &p);
		printf("%lld\n", qpow(2ll, dfs(phi(p)), p) % p);
	}
}