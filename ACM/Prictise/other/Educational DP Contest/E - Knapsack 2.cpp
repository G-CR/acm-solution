#include <bits/stdc++.h>
using namespace std;

int n, W, w[102], v[102];
int dp[103][100005];

int main() {
	scanf("%d %d", &n, &W);
	int sum = 0;
	for(int i = 1;i <= n; i++) {
		scanf("%d %d", &w[i], &v[i]);
		sum += v[i];
	}
	for(int i = 0;i <= n; i++) {
		for(int j = 0;j <= sum; j++) {
			dp[i][j] = 1e9;
		}
	}
	
	dp[0][0] = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = sum;j >= 0; j--) {
			if(j-v[i] < 0) dp[i][j] = dp[i-1][j];
			else dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]]+w[i]);
		}
	}
	
	
	int ans = 0;
	for(int i = sum;i >= 0; i--) if(dp[n][i] <= W) {
		ans = i;
		break;
	} 
	
	printf("%d\n", ans);
}