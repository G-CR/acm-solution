#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int n;
char s[200005];
long long pre[200005][4];

void init() {
	for(int i = 1;i <= n; i++) {
		char now = s[i]!='?'?s[i]:'d';
		int pos = now-'a';
		for(int j = 0;j < 4; j++) {
			if(j == pos) pre[i][j] = pre[i-1][j]+1;
			else pre[i][j] = pre[i-1][j];
		}
	}
}

long long cal(int l, int r, int ch) {
	return pre[r][ch] - pre[l-1][ch];
}

long long qpow(long long x, long long n) { 
	if(n < 0) return 0;
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

int main() {
	scanf("%d", &n);
	scanf("%s", s+1);
	init();
	
	long long ans = 0;
	for(int i = 1;i <= n; i++) {
		if(s[i] == 'b' || s[i] == '?') {
			long long a = cal(1, i-1, 3), b = cal(i+1, n, 3);
			ans = (ans + cal(1, i-1, 3)*cal(i+1, n, 3) % mod * qpow(3ll, a+b-2) % mod) % mod;
			ans = (ans + cal(1, i-1, 0)*cal(i+1, n, 3) % mod * qpow(3ll, a+b-1) % mod) % mod;
			ans = (ans + cal(1, i-1, 3)*cal(i+1, n, 2) % mod * qpow(3ll, a+b-1) % mod) % mod;
			ans = (ans + cal(1, i-1, 0)*cal(i+1, n, 2) % mod * qpow(3ll, a+b) % mod) % mod;
		}
	}
	
	printf("%lld\n", ans);
}