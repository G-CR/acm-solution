#include <bits/stdc++.h>
using namespace std;

int n, a[33], root[33][33], dp[33][33];

int dfs(int l, int r) {
	if(dp[l][r]) return dp[l][r];
	if(l > r) return 1;
	if(l == r) return a[l];
	int res = 0;
	for(int i = l; i <= r; i++) {
		int now = dfs(l,i-1) * dfs(i+1, r) + a[i];
		if(res < now) {
			res = now;
			root[l][r] = i;
		}
	}
	return dp[l][r] = res;
}

void print(int l, int r) {
	if(l > r) return;
	if(l == r) {
		printf("%d ", l);
		return;
	}
	printf("%d ", root[l][r]);
	print(l, root[l][r]-1);
	print(root[l][r]+1, r);
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", dfs(1, n));
	print(1, n);
}