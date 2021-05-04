#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e8;

ll a, p, b;

ll bsgs() {
	if(1 % p == b % p) return 0;
	unordered_map<int, int> mp;
	int k = sqrt(p) + 1;
	for(ll i = 0, j = b % p; i <= k-1; i++, j = (j*a)%p) mp[j] = i;
	ll ak = 1;
	for(int i = 1; i <= k; i++) ak = ak * a % p;
	for(ll i = 1, j = ak; i <= k; i++) {
		if(mp.count(j)) return i * k - mp[j];
		j = (j * ak) % p;
	}
	return -1;
}

int main() {
	scanf("%lld %lld %lld", &p, &a, &b);
	ll ans = bsgs();
	if(ans == -1) puts("no solution");
	else printf("%lld\n", ans);
}