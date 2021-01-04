#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005], num[200005];
long long dp[200005][2];

long long dfs(long long pos, bool qu) {
	if(pos == a[n]+1) {
		return 0;
	}
	if(dp[pos][qu]) return dp[pos][qu];
	
	long long now = 0, res1 = 0, res2 = 0;
	if(qu == 1) {
		now = num[pos] * pos;
		res1 = now + dfs(pos+1, 0);
	}
	else {
		res2 = max(dfs(pos+1, 0), dfs(pos+1, 1));
	}
	
	return dp[pos][qu] = max(res1, res2);
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		num[a[i]]++;
	}
	sort(a+1, a+1+n);
	long long ans = max(dfs(1,0), dfs(1,1));
	
	printf("%lld\n", ans);
}