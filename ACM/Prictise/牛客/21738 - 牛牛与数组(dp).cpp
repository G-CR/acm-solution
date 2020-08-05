#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int dp[11][100005];
int n, k;

int main() {
	scanf("%d %d", &n, &k);
	for(int j = 1;j <= k; j++) dp[1][j] = 1;
	for(int i = 2;i <= n; i++) {
		int sumall = 0;
		for(int j = 1;j <= k; j++) sumall = (sumall + dp[i-1][j]) % mod;
		for(int j = 1;j <= k; j++) {
			int sumno = 0;
			for(int p = j+j;p <= k; p += j) {
				sumno = (sumno + dp[i-1][p]) % mod;
			}
			dp[i][j] = (sumall - sumno) % mod;
		}
	}
	int ans = 0;
	for(int j = 1;j <= k; j++) ans = (ans+dp[n][j])%mod;
	printf("%d\n", (ans+mod)%mod);
}