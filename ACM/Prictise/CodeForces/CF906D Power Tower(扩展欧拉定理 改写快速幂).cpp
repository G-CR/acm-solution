#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll w[100005], m;
map <int, int> ol;

ll phi(ll n) {
	ll ans = n;
	for(ll i = 2 ; i*i<=n ; i++ ) {
		if(!(n%i)){
			ans = ans/i*(i-1) ;
			while(n%i == 0 ){
				n/=i ;
			}
		}
	}
	if(n>1) ans = ans/n*(n-1);
	return ans;
}

ll qpow(ll x, ll n, ll mod) {
	ll res = 1;
	for(; n; n >>= 1) {
		if(n & 1) {
			res = res * x;
			if(res > mod) res = res % mod + mod;
		}
		x = x * x;
		if(x > mod) x = x % mod + mod;
	}
	
	return res;
}

ll dfs(int l, int r, ll mod) {
	if(l == r+1 || mod == 1) return 1;
	if(!ol[mod]) ol[mod] = phi(mod);
	ll res = qpow(w[l], dfs(l+1, r, ol[mod]), mod);
	return res;
}

int main() {
	scanf("%d %lld", &n, &m);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &w[i]);
	}
	
	int q; scanf("%d", &q);
	while(q--) {
		int l, r; scanf("%d %d", &l, &r);
		printf("%lld\n", dfs(l, r, m)%m);
	}
}