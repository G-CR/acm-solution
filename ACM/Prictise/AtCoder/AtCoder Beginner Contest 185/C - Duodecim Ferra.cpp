#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll dp[300][20];

ll dfs(int p, int num) {
	if(num == 12) return 1;
	if(p+1 >= n) return 0;
	if(dp[p][num] != -1) return dp[p][num];
	ll res = 0;
	for(int i = p+1; i < n; i++) {
		res += dfs(i, num+1);
	}
	return dp[p][num] = res;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	printf("%lld\n", dfs(0, 1));
}