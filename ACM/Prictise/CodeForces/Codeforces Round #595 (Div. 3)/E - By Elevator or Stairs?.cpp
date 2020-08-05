#include <bits/stdc++.h>
using namespace std;

int n, c;
int a[200005], b[200005], ans[200005], dp[200005][2];



int main() {
	bool ok = 0;
	scanf("%d %d", &n, &c);
	for(int i = 1;i <= n-1; i++) scanf("%d", &a[i]);
	for(int i = 1;i <= n-1; i++) scanf("%d", &b[i]);
	
	dp[1][0] = ans[1] = 0; dp[1][1] = c;
	for(int i = 2;i <= n; i++) {
		dp[i][0] = min(dp[i-1][1]+a[i-1], dp[i-1][0]+a[i-1]);
		dp[i][1] = min(dp[i-1][1]+b[i-1], dp[i-1][0]+b[i-1]+c);
		ans[i] = min(dp[i][0], dp[i][1]);
	}
	for(int i = 1;i <= n; i++) printf("%d ", ans[i]);
	puts("");
}