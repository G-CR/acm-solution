#include <bits/stdc++.h>
using namespace std;

int n, x;
int dp[505][505];
vector <int> g[505];

int dfs(int ceng, int pos) {
	if(ceng == n) return 0;
	if(dp[ceng][pos] != -1e9) return dp[ceng][pos];
	return dp[ceng][pos] = max(dfs(ceng+1, pos)+g[ceng][pos], dfs(ceng+1, pos+1)+g[ceng][pos]);
}

int main() {
	scanf("%d", &n);
	for(int i = 0;i <= n; i++) for(int j = 0;j <= n; j++) dp[i][j] = -1e9;
	for(int i = 0;i < n; i++) {
		for(int j = 1;j <= i+1; j++) {
			scanf("%d", &x);
			g[i].push_back(x);
		}
	}
	printf("%d\n", dfs(0,0));
}