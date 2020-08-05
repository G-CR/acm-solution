#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e16;
int n;
long long dp[1000006][5], a[1000006];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	for(int i = 0;i <= n; i++) {
		for(int j = 0;j <= 4; j++) dp[i][j] = -inf;
	}
	
	dp[0][0] = 0;
	
	for(int i = 1;i <= n; i++) {
		for(int j = 0;j <= 4; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i-1][(j+a[i])%5]+a[i]);
		}
	}
	
//	for(int i = 1;i <= n; i++) {
//		for(int j = 0;j <= 4; j++) {
//			printf("dp[%d][%d] = %lld ", i, j, dp[i][j]);
//		}
//		puts("");
//	}
	printf("%lld\n", dp[n][0]);
}