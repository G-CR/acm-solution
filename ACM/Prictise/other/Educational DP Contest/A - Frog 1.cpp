#include <bits/stdc++.h>
using namespace std;

int dp[100005], h[100005], n;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) scanf("%d", &h[i]);
	dp[1] = 0; 
	dp[2] = dp[1]+abs(h[2]-h[1]);
	for(int i = 3;i <= n; i++) {
		dp[i] = min(dp[i-1]+abs(h[i]-h[i-1]), dp[i-2]+abs(h[i]-h[i-2]));
	}
	
	printf("%d\n", dp[n]);
}