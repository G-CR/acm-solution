#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, m;
char a[2003][2003];
int dp[2003][2003];

int dfs(int x, int y) {
	if(x == n && y == m) return 0;
	if(dp[x][y] != inf) return dp[x][y];
	int turn = (x + y) % 2;
	if(!turn) {
		int res = -inf;
		if(x + 1 <= n) res = max(res, dfs(x+1, y) + (a[x+1][y] == '+' ? 1 : -1));
		if(y + 1 <= m) res = max(res, dfs(x, y+1) + (a[x][y+1] == '+' ? 1 : -1));
		return dp[x][y] = res;
	}
	else {
		int res = inf;
		if(x + 1 <= n) res = min(res, dfs(x+1, y) - (a[x+1][y] == '+' ? 1 : -1));
		if(y + 1 <= m) res = min(res, dfs(x, y+1) - (a[x][y+1] == '+' ? 1 : -1));
		return dp[x][y] = res;
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf(" %c", &a[i][j]);
			dp[i][j] = inf;
		}
	}
	
	int ans = dfs(1, 1);
	
	if(ans > 0) puts("Takahashi");
	else if(ans < 0) puts("Aoki");
	else puts("Draw");
}