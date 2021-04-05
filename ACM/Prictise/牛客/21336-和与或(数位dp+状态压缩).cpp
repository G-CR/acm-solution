#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+9;

int n;
long long r[12], dp[65][1<<12];

long long dfs(int pos, int lim) {
	if(pos < 0) return 1;
	if(~dp[pos][lim]) return dp[pos][lim];
	
	long long res = 0, now = 0;
	for(int i = 1; i <= n; i++) {
		if(r[i] & (1ll << pos)) 
			now |= (1 << (i-1));
	}
	
	res = (res + dfs(pos-1, lim | now)) % mod;
	for(int i = 1; i <= n; i++) {
		if((1<<(i-1)) & lim)
			res = (res + dfs(pos-1, lim | now)) % mod;
		else if((1<<(i-1)) & now)
			res = (res + dfs(pos-1, (lim | now) ^ (1<<(i-1)))) % mod;
	}
	
	return dp[pos][lim] = res;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &r[i]);
	}
	
	printf("%lld\n", dfs(61, 0));
}