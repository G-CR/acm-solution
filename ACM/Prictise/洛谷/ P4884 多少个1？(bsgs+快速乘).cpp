#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll p, b, a;

ll mul(ll a, ll b, ll P) {
	ll L = a * (b >> 25ll) % P * (1ll << 25) % P;
	ll R = a * (b & ((1ll << 25) - 1)) % P;
	return (L + R) % P;
}

ll bsgs() {
	if(1 % p == b % p) return 0;
	unordered_map<ll, int> mp;
	int k = sqrt(p) + 1;
	for(ll i = 0, j = b % p;i <= k-1; i++, j = mul(j, a, p)) mp[j] = i;
	
	ll ak = 1;
	for(int i = 1;i <= k; i++) ak = mul(ak, a, p);
	
	for(ll i = 1, j = ak; i <= k; i++) {
		if(mp.count(j)) return i*k-mp[j];
		j = mul(j, ak, p);
	}
	return -1;
}

int main() {
	scanf("%lld %lld", &b, &p);
	b = (b * 9 + 1) % p;
	a = 10ll % p;
	ll ans = bsgs();
	printf("%lld\n", ans);
}