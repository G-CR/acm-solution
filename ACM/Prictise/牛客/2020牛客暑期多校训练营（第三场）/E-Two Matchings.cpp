#include <bits/stdc++.h>
using namespace std;

int _, n;
long long dp[200005], a[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) scanf("%lld", &a[i]);
		sort(a+1, a+1+n);
		dp[0] = 0;
		dp[4] = a[4]-a[1];
		dp[6] = a[6]-a[1];
		dp[8] = a[8]-a[5]+a[4]-a[1];
		for(int i = 10; i <= n; i += 2) {
			dp[i] = min(dp[i-4]+a[i]-a[i-3], dp[i-6]+a[i]-a[i-5]);
		}
		printf("%lld\n", 2*dp[n]);
	}
}