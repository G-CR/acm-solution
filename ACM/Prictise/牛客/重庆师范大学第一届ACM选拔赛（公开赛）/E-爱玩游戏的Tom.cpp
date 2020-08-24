#include <bits/stdc++.h>
using namespace std;

int N, W;
int w[102], v[102];
long long dp[102][100005];

long long dfs(int pos, int can) {
	if(dp[pos][can]) return dp[pos][can];
	if(pos == N+1) return dp[pos][can] = 0;
	else if(can < w[pos]) return dp[pos][can] = dfs(pos+1, can);
	else return dp[pos][can] = max(dfs(pos+1, can), dfs(pos+1, can-w[pos])+v[pos]);
}

int main() {
	scanf("%d %d", &N, &W);
	for(int i = 1;i <= N; i++) {
		scanf("%d %d", &w[i], &v[i]);
	}
	printf("%lld\n", dfs(1, W));
}