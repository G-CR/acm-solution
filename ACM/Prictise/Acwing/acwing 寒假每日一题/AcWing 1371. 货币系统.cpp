#include <bits/stdc++.h>
using namespace std;

int n, v;
long long a[10004];
long long dp[30][10004];

long long dfs(int pos, int sheng) {
	if(pos == n+1) {
		if(!sheng) return 1;
		return 0;
	}
	if(dp[pos][sheng] != -1) return dp[pos][sheng];
	
	long long now = 0;
	for(int i = 0; a[pos]*i <= sheng; i++) {
		now += dfs(pos+1, sheng-a[pos]*i);
	}
	
	return dp[pos][sheng] = now;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &v);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	printf("%lld\n", dfs(1, v));
}