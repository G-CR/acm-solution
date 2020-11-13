#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int dp[1003][1003];
char g[1003][1003];
int h, w;

int main() {
	memset(dp, 0, sizeof(dp));
	dp[1][1] = 1;
	scanf("%d %d", &h, &w);
	for(int i = 1;i <= h; i++) {
		for(int j = 1;j <= w; j++) {
			scanf(" %c", &g[i][j]);
		}
	}
	
	for(int i = 1;i <= h; i++) {
		for(int j = 1;j <= w; j++) {
			if(g[i][j] == '#') continue;
			if(dp[i-1][j]) dp[i][j] = (dp[i][j] + dp[i-1][j])%mod;
			if(dp[i][j-1]) dp[i][j] = (dp[i][j] + dp[i][j-1])%mod;
		}
	}
	
//	for(int i = 1;i <= h; i++) {
//		for(int j = 1;j <= w; j++) {
//			printf("%d ", dp[i][j]);
//		}
//		puts("");
//	}
	printf("%d\n", (dp[h][w]+mod)%mod);
}