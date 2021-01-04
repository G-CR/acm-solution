#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int _, n, m, k, a[200005];
long long fac[200005]; // 阶乘表

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
	for(int i = 1;i < 200005; i++) {
		fac[i] = (fac[i-1]*i)%mod;
	}
}

long long comb(long long n, long long k) {
	if(k > n) return 0;
	if(k == 1) return n;
	return (fac[n]*inv(fac[k])%mod * inv(fac[n-k])%mod);
}

int main() {
	solve();
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		int l = 1, r = 1;
		long long ans = 0;
		while(r <= n) {
			if(a[r]-a[l] <= k) {
				long long len = r-l+1;
				if(len >= m) {
					ans = (ans + comb(len-1, m-1)) % mod;
				}
				r++;
			}
			else {
				l++;
			}
		}
		
		printf("%lld\n", ans);
	}
}