#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
ll a, p, b;

ll bsgs() {
	unordered_map <int, int> mp;
	int k = sqrt(p) + 1;
	for(ll i = 0, j = b % p; i <= k-1; i++, j = (j*a)%p)
		mp[j] = i;
	
	ll ak = 1;
	for(int i = 1; i <= k; i++) ak = ak * a % p;
	for(ll i = 1, j = ak; i <= k; i++) {
		if(mp.count(j)) return i * k - mp[j];
		j = (j * ak % p);
	}
	return -1;
}

int main() {
	b = 1;
	scanf("%lld %lld", &p, &a);
	if(__gcd(a, p) != 1) return puts("Let's go Blue Jays!"), 0;
	ll ans = bsgs();
	if(ans == -1) puts("Let's go Blue Jays!");
	else printf("%lld\n", ans);
}