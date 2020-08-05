#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans = -1,dp[10004][104];
int a[10004];

int dfs(int pos, int can) {
	if(pos > n){
		if(can == 0) return 0;
		else{
			return -1000000000;
		}
	}
	if(dp[pos][can] != -1000000000) return dp[pos][can];
	if(can<=0)return dp[pos][can]=dfs(pos+1, can);
	return dp[pos][can]=max(dfs(pos+k, can-1)+a[pos], dfs(pos+1, can));
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=m;j++){
			dp[i][j]=-1000000000;
		}
	}
	
	printf("%d\n",dfs(1, m));
}