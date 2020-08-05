#include <bits/stdc++.h>
using namespace std;

int _, n, k;
long long sum[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &sum[i]);
			sum[i] += sum[i-1];
		}
		
		long long Max = -1e18, ans = -1e18;
		for(int i = k;i+k <= n; i++) {
			Max = max(Max, sum[i]-sum[i-k]);
			ans = max(ans, Max+sum[i+k]-sum[i]);
		}
		
		printf("%lld\n", ans);
	}
}