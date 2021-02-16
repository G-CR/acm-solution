#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1e9+7;

int _;
ll n, m, k;

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

long long c(long long n, long long r) {
	if(n < r) return 0;
	if(n-r < r) r = n-r;
	long long a = 1,b = 1;
	for(int i = 0; i < r; i++)
		a = (a*(n-i))%mod, b = (b*(i+1))%mod;
	return a*qpow(b, mod-2)%mod;
}

int main() {
	solve();
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %lld", &n, &m, &k);
		ll ans = 0, fh = 1;
		
		for(ll i = 0;i < k; i++, fh *= -1) {
			ans=(ans + fh * comb(k,k-i) * (k-i) % mod * qpow(k-i-1,n-1) % mod + mod)%mod;
		}
		
		ans = (ans * c(m, k)) % mod;
		
		printf("%lld\n", (ans+mod)%mod);
	}
}