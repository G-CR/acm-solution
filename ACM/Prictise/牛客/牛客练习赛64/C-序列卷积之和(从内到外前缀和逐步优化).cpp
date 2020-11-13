#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
int n;
long long a[200005];
long long pre1[200005], pre2[200005], pre3[200005], pre4[200005], pre5[200005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf("%lld", &a[i]);
	for(int i = 1;i <= n; i++) {
		pre1[i] = (pre1[i-1] + a[i]) % mod;
		pre2[i] = (pre2[i-1] + a[i]*pre1[i-1]) % mod;
		pre3[i] = (pre3[i-1] + pre1[i]*pre1[i]) % mod;
		pre4[i] = (pre4[i-1] + pre1[i]) % mod;
		pre5[i] = (pre5[i-1] + pre2[i]) % mod;
	}
	
	long long ans = 0;
	for(int l = 1;l <= n; l++) {
		ans = (ans + (pre3[n]-pre3[l-1])%mod - pre1[l-1]*(pre4[n]-pre4[l-1])%mod - (pre5[n]-pre5[l-1])%mod + ((long long)(n-l+1))*pre2[l-1]%mod) % mod;
		
//		for(int r = l;r <= n; r++) {
//		ans += pre1[r]*(pre1[r]-pre1[l-1]) - (pre2[r]-pre2[l-1]);
////			for(int i = l;i <= r; i++) {
////				ans += a[i]*(pre1[r]-pre1[i-1]);     
//////				for(int j = i;j <= r; j++) {
//////					ans += a[i]*a[j];
//////				}
////			}
//		}
	}
	
	printf("%lld\n", (ans+mod)%mod);
}