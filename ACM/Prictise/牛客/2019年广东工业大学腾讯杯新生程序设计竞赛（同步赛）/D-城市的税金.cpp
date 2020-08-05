#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, m, x, l, r;
ll p[105];
map<ll, ll> mp;

ll change(ll x) {
	return x*251%996*404*123;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &p[i]);
	}
	
	while(m--) {
		scanf("%d %d %d", &x, &l, &r);
		if(x == 1) {
			for(int i = l; i <= r; i++) {
				p[i] = change(p[i]);
			}
			//for(int i = 1;i <= n; i++) printf("%lld ", p[i]); puts("");
		}
		
		else {
			ll ans = 0;
			mp.clear();
			for(int i = l;i <= r; i++) {
				mp[p[i]]++;
				ans = max(ans, mp[p[i]]);
			}
			printf("%lld\n", ans);
		}
	}
}