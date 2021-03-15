#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e4+7;
long long a, b, k, n, m;

long long qpow(long long x, long long n) {
	long long res = 1;
	for (; n; n >>= 1, x = x * x % mod)
		if (n & 1) res = res * x % mod;
	return res;
}

long long c(long long n, long long r) {
	if(n < r) return 0;
	if(n-r < r) r = n-r;
	long long a = 1,b = 1;
	for(int i = 0; i < r; i++)
		a = (a*(n-i))%mod, b = (b*(i+1))%mod;
	return a*qpow(b, mod-2)%mod;
}

int main() {
	scanf("%lld %lld %lld %lld %lld", &a, &b, &k, &n, &m);
	printf("%lld\n", c(k, n) * qpow(a, n) % mod * qpow(b, m) % mod);
}