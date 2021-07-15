#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
const int mod = 998244353;

long long qpow(long long x, long long n) {
	long long res = 1;
	for (; n; n >>= 1, x = x * x % mod)
		if (n & 1) res = res * x % mod;
	return res;
}

int n, f[N];

int find(int x) {
	if(f[x] == x) return x;
	return f[x] = find(f[x]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) f[i] = i;
	for(int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		int u = find(x);
		int v = find(i);
		if(u != v) f[u] = v;
	}
	
	long long num = 0;
	for(int i = 1; i <= n; i++) {
		int fa = find(i);
		if(fa == i) num++;
	}
	
	printf("%lld\n", qpow(2, num)-1);
}