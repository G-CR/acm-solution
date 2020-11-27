#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;
long long fac[200005];
long long n;

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

long long inv(long long a, long long b){  // b为模数 传参-2
	long long res=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) res=1ll*res*a%mod;  
	return res;
}

int main() {
	scanf("%lld", &n);
	fac[1] = 1; fac[2] = 1;
	for(int i = 3;i <= 200000; i++) {
		fac[i] = (fac[i-1] + fac[i-2]) % mod;
	}
	
	long long now = qpow(2, n);
	printf("%lld\n", (fac[n] * inv(now, mod-2))%mod);
}