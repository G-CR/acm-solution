#include <bits/stdc++.h>
using namespace std;

int _, cas;
long long n, k, mod, a[1002];

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

int main() {
	scanf("%d", &_);
	while(_--) {
		long long ans = 0;
		scanf("%lld %lld %lld", &n, &k, &mod);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
			ans = (ans + (qpow(n, k-1)*k%mod*a[i])%mod)%mod;
		}
		
		printf("Case %d: %lld\n", ++cas, ans);
	}
}