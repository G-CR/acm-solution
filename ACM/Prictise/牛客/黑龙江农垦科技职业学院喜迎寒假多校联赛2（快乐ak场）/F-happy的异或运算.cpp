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
	string s = "";
	while(n) {
		s += (n%2)+'0';
		n >>= 1;
	}
	int num = s.length();
	long long ans = 0;
	int k = 0;
	while(num--) {
		ans += qpow(2, k++);
	}
	
	printf("%lld\n", ans);
}