#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;

int _, n, k;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		ll ans = 1;
		for(int i = 1; i <= k; i++) {
			ans = (ans * n) % mod;
		}
		
		printf("%lld\n", ans);
	}
}