#include <iostream>
using namespace std;

int m, n, pos;
double t[200][200], dp[10004][200], x;

int main() {
	while(~scanf("%d", &m)) {
		int len = m*(m-1)*(m-2)/6;
		for(int i = 1;i <= len; i++) {
			dp[0][i] = 1;
			for(int j = 1;j <= len; j++) {
				scanf("%lf", &t[i][j]);
			}
		}
		
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &pos); pos++; x = 0;
			for(int j = 1;j <= len; j++) {
				dp[i][j] = dp[i-1][j] * t[j][pos];
				x = max(x, dp[i][j]);
			}
			dp[i][pos] = x;
		}
		printf("%.6lf\n", x);
	}
}