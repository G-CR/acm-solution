#include <bits/stdc++.h>
using namespace std;

int t, m;
int tim[102], val[102];
int dp[102][1003];

int dfs(int pos, int sheng) {
	if(pos == m+1) return 0;
	if(dp[pos][sheng]) return dp[pos][sheng];
	int ans1 = 0, ans2 = 0;
	if(sheng >= tim[pos]) ans1 = dfs(pos+1, sheng-tim[pos])+val[pos];
	ans2 = dfs(pos+1, sheng);
	return dp[pos][sheng] = max(ans1, ans2);
}

int main() {
	scanf("%d %d", &t, &m);
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &tim[i], &val[i]);
	}
	
	printf("%d\n", dfs(1,t));
}