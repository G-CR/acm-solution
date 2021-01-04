#include <bits/stdc++.h>
using namespace std;

int n, x;
long long lose[1003], win[1003], use[1003];
long long dp[1003][1003];

long long dfs(int pos, int sheng) {
	if(pos == n+1) return 0;
	if(dp[pos][sheng]) return dp[pos][sheng];
	long long ans1 = 0, ans2 = 0;
	if(sheng >= use[pos])
		ans1 = dfs(pos+1, sheng-use[pos]) + win[pos];
	ans2 = dfs(pos+1, sheng) + lose[pos];
	return dp[pos][sheng] = max(ans1, ans2);
}

int main() {
	scanf("%d %d", &n, &x);
	for(int i = 1;i <= n; i++) {
		scanf("%lld %lld %lld", &lose[i], &win[i], &use[i]);
	}
	
	printf("%lld\n", 5*dfs(1,x));
}