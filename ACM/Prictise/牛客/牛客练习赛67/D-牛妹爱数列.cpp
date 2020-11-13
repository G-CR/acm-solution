#include <bits/stdc++.h>
using namespace std;

int n, a[100005], dp[100005][2];

int main() {
	memset(dp, 1e9, sizeof(dp));
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	if(a[1]) dp[1][1] = 0,dp[1][0] = 1;
	else dp[1][1] = 1, dp[1][0] = 0;
	
	for(int i = 2;i <= n; i++) {
		if(a[i]) {
			dp[i][0] = min(dp[i-1][0]+1, dp[i-1][1]+1) ;
			dp[i][1] = min(dp[i-1][0]+1, dp[i-1][1]) ;
		}
		else {
			dp[i][0] = min(dp[i-1][0], dp[i-1][1]+1) ;
			dp[i][1] = min(dp[i-1][0]+1, dp[i-1][1]+1);
		}
	}
	
	printf("%d\n", dp[n][0]);
}