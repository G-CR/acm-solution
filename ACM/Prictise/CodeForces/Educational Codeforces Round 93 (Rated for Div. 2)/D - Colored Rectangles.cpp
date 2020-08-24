#include <bits/stdc++.h>
using namespace std;

int R, G, B;
int r[202], g[202], b[202];
long long dp[202][202][202];
int ans;

bool cmp(int a, int b) {
	return a > b;
}

long long dfs(int i, int j, int k) {
	if(dp[i][j][k]) return dp[i][j][k];
	long long now = 0;
	if(i <= R && j <= G)
		now = max(now, dfs(i+1, j+1, k) + r[i]*g[j]);
	if(i <= R && k <= B)
		now = max(now, dfs(i+1, j, k+1) + r[i]*b[k]);
	if(j <= G && k <= B)
		now = max(now, dfs(i, j+1, k+1) + g[j]*b[k]);
	return dp[i][j][k] = now;
}

int main() {
	scanf("%d %d %d", &R, &G, &B);
	for(int i = 1;i <= R; i++) {
		scanf("%d", &r[i]);
	} sort(r+1, r+1+R, cmp);
	for(int i = 1;i <= G; i++) {
		scanf("%d", &g[i]);
	} sort(g+1, g+1+G, cmp);
	for(int i = 1;i <= B; i++) {
		scanf("%d", &b[i]);
	} sort(b+1, b+1+B, cmp);
	
	printf("%lld\n", dfs(1, 1, 1));
}