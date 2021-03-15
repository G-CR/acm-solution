#include <bits/stdc++.h>
using namespace std;
const long long mod = 998244353;

int n, m;
long long a[1003], x;

int main() {
	scanf("%d", &n);
	for(int i = 0;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	scanf("%d", &m);
	while(m--) {
		scanf("%lld", &x);
		long long ans = 0, t = 1;
		
		for(int i = 0;i <= n; i++) {
			ans = (ans + a[i] * t) % mod;
			t = (t * x) % mod;
		}
		
		printf("%lld ", ans);
	}
}