#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll l, r;

ll solve(ll r, int x) {
	ll ans = r/x;
	for(ll Left = x*10, Right = x*10+9; Left <= r; Left*=10, Right=Right*10+9) {
		ll k = min(Right, r);
		for(ll i = Left; i <= k;) {
			ll cnt = r/i;
			ll fin = min(k, r/cnt);
			ans += cnt*(fin-i+1);
			i = fin+1;
		}
	}
	return ans;
}

int main() {
	scanf("%lld %lld", &l, &r);
	for(int i = 1;i <= 9; i++) {
		printf("%lld\n", solve(r, i)-solve(l-1, i));
	}
}