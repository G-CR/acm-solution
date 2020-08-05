#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
int n, dp[105][105], a[105], pre[105];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		pre[i] = pre[i-1]+a[i];
	}
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= n; j++) {
			if(i == j) dp[i][j] = 0;
			else dp[i][j] = inf;
		}
	}
	
	for(int len = 1;len <= n; len++) { // 区间长度
		for(int j = 1;j+len <= n+1; j++) { // 枚举起点
			int ends = j + len - 1;
			for(int i = j;i < ends; i++) { // 枚举切割点
				dp[j][ends] = min(dp[j][ends], dp[j][i]+dp[i+1][ends]+pre[ends]-pre[j-1]);
			}
		}
	}
	
	printf("%d\n", dp[1][n]);
}