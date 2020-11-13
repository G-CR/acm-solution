#include <bits/stdc++.h>
using namespace std;

int _;
string s, k = "puleyaknoi";
int dp[100005][13];

int dfs(int pos, int pk) {
	if(pk == 10) return pos-1;
	else if(pos == s.length()) return 1e9;
	if(dp[pos][pk]) return dp[pos][pk];
	
	int ans = 1e9, len = 0;
	if(s[pos] == k[pk]) {
		if(pk == 0) len = pos-1;
		int r1 = dfs(pos+1, pk+1)-len;
		int r2 = dfs(pos+1, pk);
		ans = min(ans, min(r1, r2));
	}
	else ans = dfs(pos+1, pk);
	
	return dp[pos][pk] = ans;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		memset(dp, 0, sizeof dp);
		cin >> s;
		int t = dfs(0, 0);
		printf("%d\n", t>1e5?-1:t);
	}
}