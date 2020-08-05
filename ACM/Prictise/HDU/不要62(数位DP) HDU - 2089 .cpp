#include <bits/stdc++.h>
using namespace std;

int dp[10][2][2],a[10];
int m,n;

int dfs(int pos,int sta,int lim) {
	if(pos == 0) return 1;
	if(dp[pos][sta][lim]) return dp[pos][sta][lim];
	int up = (lim == 1)?a[pos]:9;
	int ans = 0;
	for(int i = 0;i <= up; i++) {
		if(i == 4 || (sta && i == 2)) continue;
		ans += dfs(pos-1,(i == 6), lim && i == up);
	}
	return dp[pos][sta][lim] = ans;
}


int solve(int n) {
	memset(dp,0,sizeof(dp));
	int cnt = 0;
	while(n) {
		a[++cnt] = n%10;
		n /= 10;
	}
	return dfs(cnt, 0, 1);
}

int main() {
	while(~scanf("%d %d", &n, &m) && n && m) {
		printf("%d\n", solve(m)-solve(n-1));
	}
	return 0;
}