#include <bits/stdc++.h>
using namespace std;

int n, a[30];

int dfs(int p, int ans, int now) {
	if(p == n+1) {
		return ans ^ now;
	}
	int res = (1<<30)+1;
	res = min(res, dfs(p+1, ans, now|a[p]));
	res = min(res, dfs(p+1, ans^now, a[p]));
	return res;
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	printf("%d\n", dfs(1, 0, 0));
}