#include <bits/stdc++.h>
using namespace std;

long long a, b, p;

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % p) 
		if (n & 1) res = res * x % p; 
	return res; 
}

int main() {
	scanf("%lld %lld %lld", &a, &b, &p);
	printf("%lld\n", qpow(a, b) % p);
}