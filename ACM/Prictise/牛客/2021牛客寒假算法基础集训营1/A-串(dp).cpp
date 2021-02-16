#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
typedef long long ll;
int dp[1000006][2][2];
int n;

int dfs(int pos, bool u, bool s) {
	if(pos == 0) {
		if(u && s) return 1;
		else return 0;
	}
	
	if(dp[pos][u][s] != -1) return dp[pos][u][s] % mod;
	if(!u) return dp[pos][u][s] = ((ll)dfs(pos-1, 0, 0) * 25 + dfs(pos-1, 1, 0)) % mod;
	if(u && !s) return dp[pos][u][s] = ((ll)dfs(pos-1, 1, 0) * 25 + dfs(pos-1, 1, 1))% mod;
	else return dp[pos][u][s] = ((ll)dfs(pos-1, 1, 1) * 26) % mod;
}

int main() {
	scanf("%d", &n);
	memset(dp, -1, sizeof(dp));
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = (ans + dfs(i, 0, 0)) % mod;
	}
	
	printf("%d\n", ans);
}