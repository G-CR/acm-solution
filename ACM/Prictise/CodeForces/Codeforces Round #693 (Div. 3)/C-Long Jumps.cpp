#include <bits/stdc++.h>
using namespace std;

int _, n;
long long a[200005], dp[200005];

long long dfs(int pos) {
	if(pos > n) return 0;
	if(dp[pos]) return dp[pos];
	return dp[pos] = dfs(pos+a[pos]) + a[pos];
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 0;i <= n; i++) dp[i] = 0;
		
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		
		long long ans = -1;
		for(int i = 1;i <= n; i++) {
			ans = max(ans, dfs(i));
		}
		printf("%lld\n", ans);
	}
}