#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int _, n;
long long ans[20000007];
long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

int main() {
	long long ny = qpow(2, mod-2);
	long long inv2 = ny;
	long long res = 1, fin = 0;
	for(int i = 1;i <= 20000000; i++) {
		res = res*(1-ny+mod)%mod;
		ny = ny*inv2%mod;
		fin ^= res;
		ans[i] = fin;
	}
	
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		printf("%lld\n", ans[n]);
	}
}