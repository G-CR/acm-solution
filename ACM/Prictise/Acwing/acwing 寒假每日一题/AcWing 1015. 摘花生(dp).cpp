#include <bits/stdc++.h>
using namespace std;

int _;
int n, m;
int a[103][103], dp[103][103];

int dfs(int r, int c) {
	if(r > n || c > m) return 0;
	if(dp[r][c] != -1) return dp[r][c];
	return dp[r][c] = max(dfs(r, c+1)+a[r][c], dfs(r+1, c)+a[r][c]);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				scanf("%d", &a[i][j]);
				dp[i][j] = -1;
			}
		}
		
		printf("%d\n", dfs(1,1));
	}
}