#include <bits/stdc++.h>
using namespace std;
const int mod = 20000311;

int x, n, cnt[500005];

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &x);
		if(x <= n) cnt[x]++;
	}
	
	long long ans = 0, p = 1, q = n;
	for(long long i = 1;i <= n+1; i++) {
		q -= cnt[i];
		ans = (ans + ((p * qpow(2, q)) % mod * i) % mod) % mod;
		p = (p * (qpow(2, cnt[i])-1)) % mod;
	}
	
	printf("%lld\n", ans);
}