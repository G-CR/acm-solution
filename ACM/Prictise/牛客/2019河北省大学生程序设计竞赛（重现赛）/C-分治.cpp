#include <bits/stdc++.h>
using namespace std;

int _, n;
int cost[105];
long long dp[105][105];

long long dfs(int l, int r) {
	long long ans = 1e18;
	if(l >= r) return 0;
	if(dp[l][r]) return dp[l][r];
	for(int i = l;i <= r; i++) {
		ans = min(ans, dfs(l, i-1) + dfs(i+1, r) + cost[i]*(r-l));
	}
	return dp[l][r] = ans;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		memset(dp, 0, sizeof dp);
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &cost[i]);
		}
		
		printf("%lld\n", dfs(1, n));
	}
}