#include <bits/stdc++.h>
#define ll long long
using namespace std;

int t;

int main() {
	scanf("%d", &t);
	while(t--) {
		ll n,x;
		scanf("%lld %lld", &n, &x);
		ll d,h,good = -1,maxn = -1;
		for(int i = 1;i <= n; i++) {
			scanf("%lld %lld", &d, &h);
			maxn = max(maxn, d);
			good = max(good, d-h);
		}
		if(maxn >= x) {
			puts("1");
			continue;
		}
		if(good <= 0) {
			puts("-1");
			continue;
		}
		ll ans = 1;
		x -= maxn;
		
		ans += (x / good);
		if(x % good != 0) ans++;
		printf("%lld\n", ans);
	}
}