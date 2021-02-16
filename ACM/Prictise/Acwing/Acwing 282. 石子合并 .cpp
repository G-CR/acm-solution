#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

int n;
int a[303], pre[303];
int dp[303][303];

int dfs(int l, int r) {
	if(l == r) return 0;
	if(dp[l][r]) return dp[l][r];
	int res = inf;
	for(int i = l; i < r; i++) {
		res = min(res, dfs(l,i)+dfs(i+1, r) + (pre[r]-pre[l-1]));
	}
	return dp[l][r] = res;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		pre[i] = pre[i-1] + a[i];
	}
	
	printf("%d\n", dfs(1, n));
}