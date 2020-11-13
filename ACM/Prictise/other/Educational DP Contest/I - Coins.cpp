#include <bits/stdc++.h>
using namespace std;

int n;
double p[3003], dp[3003][3003];

int main() {
	memset(dp, 0, sizeof(dp));
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lf", &p[i]);
	}
	
	dp[1][1] = p[1];
	dp[1][0] = 1.0-p[1];
	for(int i = 2;i <= n; i++) {
		for(int j = 0;j <= i; j++) {
			if(j == 0) dp[i][j] = dp[i-1][j]*(1-p[i]);
			else dp[i][j] = dp[i-1][j-1]*p[i] + dp[i-1][j]*(1-p[i]);
		}
	}
	
	double ans = 0;
	for(int i = (n+1)/2;i <= n; i++) {
		ans += dp[n][i];
	}
	
	printf("%.10lf\n", ans);
}