#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int n;
long long a[500005], presum[500005], res1, res2;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		res1 = (res1+(a[i]*a[i]%mod))%mod;
		presum[i] = (presum[i-1] + a[i]) % mod;
	}
	res1 = (res1 * (n-1)) % mod;
	
	for(int i = 1;i <= n; i++) {
//		cout << presum[i] << " ";
		res2 = (res2 + ((presum[n]-presum[i])%mod*a[i])%mod)%mod;
	}
	res2 = (2*res2)%mod;
//	puts("");
	
//	cout << "res1 = " << res1 << " res2 = " << res2 << endl;
	printf("%lld\n", (res1-res2+mod)%mod);
}