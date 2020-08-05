#include <bits/stdc++.h>
using namespace std;

int n, m, k;
long long mod, a[2002][2002], num[2002][2002];

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

int main() {
	scanf("%d %d %d %lld", &n, &m, &k, &mod);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf("%lld", &a[i][j]);
		}
	}
	
	if(k == 1) puts("1");
	else {
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				while(a[i][j] > 1) {
					num[i][j]++;
					a[i][j] /= k;
				}
			}
		}
		
		long long ans = -1;
		for(int i = 1;i <= n; i++) {
			long long cnt = 0;
			for(int j = 1;j <= m; j++) {
				cnt += num[i][j];
			}
			ans = max(ans, cnt);
//			cout << "cnt = " << cnt << endl;
		}
		
		printf("%lld\n", (qpow(k, ans)+mod)%mod);
	}
}