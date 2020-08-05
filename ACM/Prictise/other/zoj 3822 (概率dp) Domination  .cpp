#include <bits/stdc++.h>
using namespace std;

int _, n, m;
double dp[55][55][2505];

int main() {
	scanf("%d", &_);
	while(_--) {
		memset(dp, 0, sizeof(dp));
		scanf("%d %d", &n, &m);
		dp[1][1][1] = 1;
		int tot = n*m;
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				for(int k = max(i,j);k <= i*j; k++) {
					dp[i][j][k] += dp[i-1][j][k-1]*(n-i+1)*j/(tot-k+1);
					dp[i][j][k] += dp[i][j-1][k-1]*(m-j+1)*i/(tot-k+1);
					dp[i][j][k] += dp[i-1][j-1][k-1]*(tot-(i-1)*m-(j-1)*n+(i-1)*(j-1))/(tot-k+1);
					if(i == n && j == m) continue;
					dp[i][j][k] += dp[i][j][k-1]*(i*j-k+1)/(tot-k+1);
				}
			}
		}
		double ans = 0;
		for(int i = 1;i <= tot; i++) ans += dp[n][m][i]*i;
		printf("%.12lf\n", ans);
	}
}