#include<bits/stdc++.h>
using namespace std;

int r, n;
int t[100005], x[100005], y[100005];
int dp[100005], maxn[100005];

int main() {
	scanf("%d %d", &r, &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d %d", &t[i], &x[i], &y[i]);
		if(t[i] >= (x[i]-1)+(y[i]-1)) dp[i] = 1;
		else dp[i] = -1e9;
		maxn[i] = dp[i];
	}

	for(int i = 1;i <= n; i++) {
		for(int j = i-1;j >= 1; j--) {
			if(t[i]-t[j] >= abs(x[i]-x[j]) + abs(y[i]-y[j])) {
				dp[i] = max(dp[i], dp[j]+1);
			}

			if(t[i]-t[j] >= 2*r) {
				dp[i] = max(dp[i], maxn[j]+1);
				break;
			}
		}

		maxn[i] = max(dp[i], maxn[i-1]);
	}

	int ans = 0;
	for(int i = 1;i <= n; i++) ans = max(ans, dp[i]);
	printf("%d\n", ans);
}