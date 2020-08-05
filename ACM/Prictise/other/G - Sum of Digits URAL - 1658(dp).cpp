#include <bits/stdc++.h>
using namespace std;

int _, s1, s2;
int dp[1000][8500], pre[1000][8500];

void init() {
	for(int i = 0;i <= 900; i++) for(int j = 0;j <= 8100; j++) 
		dp[i][j] = 101;
		
	dp[0][0] = 0;
	for(int i = 1;i <= 900; i++) {
		for(int j = 1;j <= 8100; j++) {
			for(int k = 1;k <= 9; k++) {
				if(i-k<0 || j-k*k<0) break;
				if(dp[i][j] > dp[i-k][j-k*k]+1) {
					dp[i][j] = dp[i-k][j-k*k]+1;
					pre[i][j] = k;
				}
			}
		}
	}
	
}

int main() {
	init();
//	for(int i = 1;i <= 900; i++) {
//		for(int j = 1;j <= 8100; j++) {
//			if(dp[i][j] >=1 && dp[i][j] <= 10)
//			printf("%d ", dp[i][j]);
//		}
//		getchar();
//	}
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &s1, &s2);
		if(s1 > 900 || s2 > 8100 || dp[s1][s2] > 100 || pre[s1][s2] == 10) {
			puts("No solution");
			continue;
		}
		
		int l = s1, r = s2;
		while(dp[l][r]) {
			int t = pre[l][r];
			printf("%d", t);
			l -= t;
			r -= t*t;
		}
		puts("");
	}
}