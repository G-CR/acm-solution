#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int dp[55][3]; // 前i个位置%3为j的个数
string s;

int main() {
	cin >> s;
	int n = s.length();
	memset(dp, 0, sizeof(dp));
	dp[0][(s[0]-'0')%3] = 1;
	for(int i = 1;i < n; i++) {
		int t = (s[i]-'0')%3;
		dp[i][t]++;
		for(int j = 0;j < 3; j++) {
			dp[i][j] += (dp[i-1][j] + dp[i-1][(j+3-t)%3])%mod;
		}
	}
	printf("%d\n", dp[n-1][0]);
}