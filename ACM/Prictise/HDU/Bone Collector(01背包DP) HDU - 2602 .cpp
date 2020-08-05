#include <bits/stdc++.h>
using namespace std;

int T, n, v, val[1005], vol[1005], dp[1005][1005];

int dfs(int i,int j) {
	if(dp[i][j]) return dp[i][j];
	if(i == n+1) return dp[i][j] = 0;
	else if(j < vol[i]) return dp[i][j] = dfs(i+1,j);
	else {
		return dp[i][j] = max(dfs(i+1,j),dfs(i+1,j-vol[i])+val[i]);
	}
}

int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d", &n, &v);
		for(int i = 1;i <= n; i++) scanf("%d", &val[i]);
		for(int i = 1;i <= n; i++) scanf("%d", &vol[i]);
		memset(dp, 0, sizeof(dp));
		printf("%d\n", dfs(1, v));
	}
}