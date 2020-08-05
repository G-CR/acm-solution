#include <bits/stdc++.h>
using namespace std;

int m,n,a[1005],dp[1005][1005],Max,Maxi;

int dfs(int i,int j) {
	if(dp[i][j]) return dp[i][j];
	if(i == n+1) return dp[i][j] = 0;
	else if(j < a[i]) return dp[i][j] = dfs(i+1,j);
	else {
		return dp[i][j] = max(dfs(i+1,j), dfs(i+1,j-a[i])+a[i]);
	}
}

int main() {
	while(~scanf("%d", &n) && n) {
		Max = -1;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			if(Max < a[i]) {
				Max = a[i];
				Maxi = i;
			}
		}
		a[Maxi] = 0;
		
		scanf("%d", &m);
		if(m < 5) printf("%d\n", m);
		else {
			memset(dp, 0, sizeof(dp));
			m -= (dfs(1, m-5) + Max);
			printf("%d\n", m);
		}
	}
}