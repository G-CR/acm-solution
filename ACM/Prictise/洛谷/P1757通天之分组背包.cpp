#include <bits/stdc++.h>
using namespace std;

int n, m;
int v[1003], val[1003], zu[1003], dp[1003][1003];
bool vis[1003];

int dfs(int pos, int sheng) {
	if(pos == n+1) return 0;
	if(dp[pos][sheng]) return dp[pos][sheng];
	int ans1 = 0, ans2 = 0;
	if(sheng >= v[pos] && !vis[zu[pos]]) {
		vis[zu[pos]] = 1;
		ans1 = dfs(pos+1, sheng-v[pos]) + val[pos];
	}
	ans2 = dfs(pos+1, sheng);
	return dp[pos][sheng] = max(ans1, ans2);
}

int main() {
	scanf("%d %d", &m, &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d %d", &v[i], &val[i], &zu[i]);
	}
	printf("%d\n", dfs(1, m));
}