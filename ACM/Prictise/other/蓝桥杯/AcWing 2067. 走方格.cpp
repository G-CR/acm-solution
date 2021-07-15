#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[35][35];

int dfs(int x, int y) {
	if(x == n && y == m) return 1;
	if(dp[x][y] != -1) return dp[x][y];
	int tx = x + 1, ty = y + 1;
	int res = 0;
	if(tx <= n && (tx % 2 || y % 2)) res += dfs(tx, y);
	if(ty <= m && (x % 2 || ty % 2)) res += dfs(x, ty);
	
	return dp[x][y] = res;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &m);
	printf("%d\n", dfs(1, 1));
}