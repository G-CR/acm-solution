#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[103][103];
long long dp[103][103];

long long dfs(int x, int y) {
	if(x == n && y == m) return a[x][y];
	if(dp[x][y] != -1e18) return dp[x][y];
	long long ans = -1e18;
	for(int i = x;i <= x+3; i++) {
		for(int j = y; (i+j-x-y) <= 3; j++) {
			if(i == x && j == y) continue;
			if(i > n || j > m) continue;
			ans = max(ans, dfs(i, j)+a[x][y]);
		}
	}
	return dp[x][y] = ans;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			dp[i][j] = -1e18;
			scanf("%lld", &a[i][j]);
		}
	}
	
	printf("%lld\n", dfs(1,1));
	return 0;
}