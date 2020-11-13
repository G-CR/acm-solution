#include <bits/stdc++.h>
using namespace std;

int dp[100005], h[100005], n, k;

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1;i <= n; i++) scanf("%d", &h[i]);
	for(int i = 1;i <= n; i++) dp[i] = 1e9;
	dp[1] = 0;
	for(int i = 2;i <= n; i++) {
		for(int j = 1;j <= k; j++) {
			if(i-j < 1) break;
			dp[i] = min(dp[i], dp[i-j]+abs(h[i-j]-h[i]));
		}
//		printf("dp[%d] = %d\n", i, dp[i]);
	}
	printf("%d\n", dp[n]);
}