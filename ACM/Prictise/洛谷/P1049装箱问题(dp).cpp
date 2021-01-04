#include <bits/stdc++.h>
using namespace std;

int V, n;
int v[20004];
int dp[33][20004];

int dfs(int pos, int sheng) {
	if(pos == n+1) return 0;
	if(dp[pos][sheng]) return dp[pos][sheng];
	int ans1 = 0, ans2 = 0;
	if(sheng >= v[pos]) {
		ans1 = dfs(pos+1, sheng-v[pos]) + v[pos];
	}
	ans2 = dfs(pos+1, sheng);
	return dp[pos][sheng] = max(ans1, ans2);
}

int main() {
	scanf("%d %d", &V, &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &v[i]);
	}
	printf("%d\n", V-dfs(1,V));
}