#include <bits/stdc++.h>
using namespace std;

int n, t;
long long dp[55][100005];
struct node {
	long long ins;
	long long des;
	long long nds;
} p[55];

bool cmp(node a, node b) {
	return a.nds * b.des < b.nds * a.des;
}

long long dfs(int pos, int now) {
	if(pos == n + 1) return 0;
	if(dp[pos][now] != -1) return dp[pos][now];
	long long np = p[pos].ins - (now+p[pos].nds) * p[pos].des;
	if(t - now >= p[pos].nds) 
		return dp[pos][now] = max(dfs(pos+1, now+p[pos].nds) + np, dfs(pos+1, now));
	else return dp[pos][now] = dfs(pos+1, now);
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d %d", &n, &t);
	for(int i = 1; i <= n; i++) scanf("%lld", &p[i].ins);
	for(int i = 1; i <= n; i++) scanf("%lld", &p[i].des);
	for(int i = 1; i <= n; i++) scanf("%lld", &p[i].nds);
	
	sort(p+1, p+1+n, cmp);
	
	printf("%lld\n", dfs(1, 0));
}