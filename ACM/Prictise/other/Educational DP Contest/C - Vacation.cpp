#include <bits/stdc++.h>
using namespace std;

int n, a[100005], b[100005], c[100005];
int dp[100005][3];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d %d", &a[i], &b[i], &c[i]);
		for(int j = 0;j < 3; j++) dp[i][j] = 0;
	}
	
	dp[1][0] = a[1]; dp[1][1] = b[1]; dp[1][2] = c[1];
	for(int i = 2;i <= n; i++) {
		for(int j = 0;j < 3; j++) {
			if(j == 0) dp[i][j] = max(dp[i-1][1]+a[i], dp[i-1][2]+a[i]);
			if(j == 1) dp[i][j] = max(dp[i-1][0]+b[i], dp[i-1][2]+b[i]);
			if(j == 2) dp[i][j] = max(dp[i-1][0]+c[i], dp[i-1][1]+c[i]);
		}
	}
	
	printf("%d\n", max(max(dp[n][0], dp[n][1]), dp[n][2]));
}