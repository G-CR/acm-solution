#include <bits/stdc++.h>
using namespace std;

int dp[3005][3005], n, ans;
long long x[3005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &x[i]);
	}
	
	for(int i = 2;i <= n; i++) {
		for(int j = 1;j <= i; j++) {
			int t = lower_bound(x+1, x+1+j, x[j] - (x[i]-x[j])) - x;
			if(x[j] - x[t] == x[i] - x[j]) {
				dp[i][j] = dp[j][t]+1;
			}
			else dp[i][j] = 2;
			ans = max(ans, dp[i][j]);
		}
	}
	printf("%d\n", ans);
}