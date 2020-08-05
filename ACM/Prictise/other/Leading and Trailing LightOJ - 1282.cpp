#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000;

int _, cas;
long long n, k;

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &n, &k);
		printf("Case %d: ", ++cas);
		double x = fmod(k*log10(n), 1);
		printf("%03lld %03lld\n", (long long)(pow(10,x)*100), qpow(n, k));
	}
}