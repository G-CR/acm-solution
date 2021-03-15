#include <bits/stdc++.h>
using namespace std;

int n, m, x;
int a[400], num[5];
int dp[41][41][41][41];

int dfs(int na, int nb, int nc, int nd) {
	if(!na && !nb && !nc && !nd) {
		return a[1];
	}
	if(dp[na][nb][nc][nd] != -1) return dp[na][nb][nc][nd];
	int res = 0;
	int t = a[1+na+nb*2+nc*3+nd*4];
	if(na) res = max(res, dfs(na-1, nb, nc, nd) + t);
	if(nb) res = max(res, dfs(na, nb-1, nc, nd) + t);
	if(nc) res = max(res, dfs(na, nb, nc-1, nd) + t);
	if(nd) res = max(res, dfs(na, nb, nc, nd-1) + t);
	
	return dp[na][nb][nc][nd] = res;
}

int main() {
	scanf("%d %d", &n, &m);
	memset(dp, -1, sizeof(dp));
	for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
	for(int i = 1;i <= m; i++) {
		scanf("%d", &x);
		num[x]++;
	}
	
	printf("%d\n", dfs(num[1], num[2], num[3], num[4]));
}