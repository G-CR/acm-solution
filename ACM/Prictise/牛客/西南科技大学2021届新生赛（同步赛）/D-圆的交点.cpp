#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int _;
long long n, m;

int main() {
	scanf("%d", &_);
	while(_--) {
		long long ans = 0;
		scanf("%lld %lld", &n, &m);
		ans = (ans + n*2 + m*2) % mod;
		ans = (ans + ((n * m) % mod * 4) % mod) % mod;
		ans = (ans + ((n+1) * (m+1)) % mod) % mod;
		
		printf("%lld\n", ans);
	}
}