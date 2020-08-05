#include <bits/stdc++.h>
using namespace std;

long long n;
long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x) 
		if (n & 1) res = res * x; 
	return res; 
}


int main() {
	scanf("%lld", &n);
	int cnt = 0, i = 0;
	bool ok = 1;
	while(n) {
		if((n&1) == 0) ok = 0; 
		n >>= 1;
		cnt++;
	}
	long long ans = 0;
	for(int i = 0;i < cnt; i++) {
		ans += qpow(2, i);
	}
	if(ok) ans--;
	printf("%lld\n", ans);
}