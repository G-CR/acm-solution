#include <bits/stdc++.h>
using namespace std;

const long long mod = 1000003;
long long fac[2000006]; // 阶乘表

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

long long inv(long long a) { // 返回逆元 费马小定理
	return qpow(a, mod-2)%mod;
}

void solve() { // 计算阶乘表
	fac[0] = 1;
	for(int i = 1;i < 2000006; i++) {
		fac[i] = (fac[i-1]*i)%mod;
	}
}

long long comb(long long n, long long k) {
	if(k > n) return 0;
	if(k == 1) return n;
	return (fac[n]*inv(fac[k])%mod * inv(fac[n-k])%mod);
}

int _;
long long n, k;

int main() {
	solve();
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lld %lld", &n, &k);
		printf("Case %d: %lld\n", ++cas, comb(n, k));
	}
}