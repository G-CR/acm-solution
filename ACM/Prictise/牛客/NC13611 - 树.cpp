#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int n, k;
long long pre[305];

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

long long C(long long x, long long y) {
	return pre[x] * qpow(pre[y]*pre[x-y]%mod, mod-2) % mod;
}

int main() {
	scanf("%d %d", &n, &k);
	pre[0] = pre[1] = 1;
	for(int i = 2;i <= n; i++) pre[i] = i*pre[i-1]%mod;
	long long ans = 0;
	for(int i = 1;i <= min(n, k); i++) {
		ans = (ans+ C(n-1, i-1) * C(k, i) % mod * pre[i] % mod)%mod;
	}
	printf("%lld\n", ans);
}