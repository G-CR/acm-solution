#include <bits/stdc++.h>
using namespace std;
const int mod = 20010905;
int dp[10];
string s;
int main() {
	cin >> s;
	int n = s.length();
	for(int i = 0;i < n; i++) {
		if(s[i] < 'a') s[i] += 32;
	}
	for(int i = 0;i < n; i++) {
		dp[1] = (dp[1] + (s[i] == 'i')) % mod;
		dp[2] = (dp[2] + dp[1]*(s[i] == 'l')) % mod;
		dp[3] = (dp[3] + dp[2]*(s[i] == 'o')) % mod;
		dp[4] = (dp[4] + dp[3]*(s[i] == 'v')) % mod;
		dp[5] = (dp[5] + dp[4]*(s[i] == 'e')) % mod;
		dp[6] = (dp[6] + dp[5]*(s[i] == 'y')) % mod;
		dp[7] = (dp[7] + dp[6]*(s[i] == 'o')) % mod;
		dp[8] = (dp[8] + dp[7]*(s[i] == 'u')) % mod;
	}
	printf("%d\n", dp[8]);
}