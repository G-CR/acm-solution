#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int _;
long long n, m;

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
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &n, &m);
		long long x = qpow(n, m);
		x = inv(x, mod-2);
		printf("%lld\n", ((1-x)+mod)%mod);
	}
}