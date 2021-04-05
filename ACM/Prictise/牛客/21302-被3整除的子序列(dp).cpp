#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
string s;
int n, a[55];
long long dp[55][3];

long long dfs(int pos, int now) {
	if(pos == n) {
		if(now == 0) return 1;
		return 0;
	}
	if(dp[pos][now] != -1) return dp[pos][now];
	long long res = 0;
	res = (res + dfs(pos+1, now)) % mod;
	res = (res + dfs(pos+1, (now+a[pos])%3)) % mod;
	
	return dp[pos][now] = res;
}

int main() {
	memset(dp, -1, sizeof(dp));
	cin >> s; n = s.length();
	for(int i = 0; i < n; i++) a[i] = s[i]-'0';
	printf("%lld\n", dfs(0, 0)-1);
}