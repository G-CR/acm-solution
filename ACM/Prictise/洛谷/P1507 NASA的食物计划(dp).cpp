#include <bits/stdc++.h>
using namespace std;

int V, M, n;
int v[55], m[55], c[55];
int dp[55][405][405];

int dfs(int pos, int sv, int sm) {
	if(pos == n+1) return 0;
	if(dp[pos][sv][sm]) return dp[pos][sv][sm];
	int res1 = 0, res2 = 0;
	if(sv >= v[pos] && sm >= m[pos]) res1 = dfs(pos+1, sv-v[pos], sm-m[pos]) + c[pos];
	res2 = dfs(pos+1, sv, sm);
	return dp[pos][sv][sm] = max(res1, res2);
}

int main() {
	scanf("%d %d %d", &V, &M, &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d %d", &v[i], &m[i], &c[i]);
	}
	printf("%d\n", dfs(1, V, M));
}