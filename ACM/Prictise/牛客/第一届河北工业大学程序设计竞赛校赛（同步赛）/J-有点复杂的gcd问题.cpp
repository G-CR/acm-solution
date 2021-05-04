#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
ll n, k;

int main() {
	scanf("%lld %lld", &n, &k);
	ll ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = (ans + i) % mod;
	}
	
	printf("%lld\n", ans);
}