#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;

int dp[10004][4][2],n;
char a[10004];

int dfs(int pos,int sta,int lim) {
	if(pos == n+1) return 1;
	if(dp[pos][sta][lim]) return dp[pos][sta][lim];
	char up = (lim == 1)?a[pos]:'z';
	long long ans = 0;
	for(char i = 'a';i <= up; i++) {
		int t = 0;
		if(i == 'c' && sta != 1) t = 1;
		else if(i == 'c' && sta == 1) t = 2;
		else if(i == 's' && sta == 2) t = 3;
		else if(i == 'u' && sta == 3) continue;
		ans = (ans + dfs(pos+1, t, lim&&(i==up)))%mod;
	}
	return dp[pos][sta][lim] = ans;
}


int main() {
	scanf("%s",a+1);
	n = strlen(a+1);
	long long tot = 0;
	for(int i = 1;i <= n; i++) {
		tot = (tot*26 + (a[i]-'a'))%mod;
	}
	tot += 1;
	long long fin = tot-dfs(1,0,1)+mod;
	printf("%lld\n", fin % mod);
}