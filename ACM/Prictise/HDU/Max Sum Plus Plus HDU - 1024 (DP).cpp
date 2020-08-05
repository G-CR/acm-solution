#include <bits/stdc++.h>
using namespace std;
const int N = 1000006;

int n,m;
int a[N],dp[N],last[N];

int main() {
	while(~scanf("%d %d", &m, &n)) {
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		memset(dp,0,sizeof(dp));
		memset(last,0,sizeof(last));
		
		int Max;
		for(int i = 1;i <= m; i++) {
			Max = -1000000000;
			for(int j = i;j <= n; j++) {
				dp[j] = max(dp[j-1]+a[j], last[j-1]+a[j]);
				last[j-1] = Max;
				Max = max(Max, dp[j]);
			}
		}
		printf("%d\n", Max);
	}
}