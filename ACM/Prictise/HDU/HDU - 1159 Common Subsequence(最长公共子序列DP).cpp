#include <bits/stdc++.h>
using namespace std;

char s[1005],t[1005];
int dp[1005][1005];

int main() {
	while(~scanf("%s %s", s, t)) {
		memset(dp, 0, sizeof(dp));
		int n1 = strlen(s), n2 = strlen(t);
		for(int i = 0;i < n1; i++) {
			for(int j = 0;j < n2; j++) {
				if(s[i] == t[j]) {
					dp[i+1][j+1] = dp[i][j] + 1;
				} else {
					dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
				}
			}
		}
		printf("%d\n", dp[n1][n2]);
	}
}