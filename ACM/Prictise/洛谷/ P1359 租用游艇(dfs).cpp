#include <bits/stdc++.h>
using namespace std;

int n, dp[202];
vector <pair<int, int> > g[202];

int dfs(int pos) {
	if(pos == n) {
		return 0;
	}
	if(dp[pos]) return dp[pos];
	int ans = 1e9;
	for(auto i: g[pos]) {
		ans = min(ans, dfs(i.first)+i.second);
	}
	return dp[pos] = ans;
}


int main() {
	scanf("%d", &n);
	for(int i = 1;i < n; i++) {
		for(int j = i+1; j <= n; j++) {
			int x; scanf("%d", &x);
			g[i].push_back({j, x});
		}
	}
	int ans = dfs(1);
	
	printf("%d\n", ans);
}