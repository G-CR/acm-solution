#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
int n, a[44];
long long dp[42][2000][42][2];

long long dfs(int pos, int sum, int pre, int cnt) {
	if(pos == n+1)  return 1;
	if(dp[pos][sum][pre][cnt] != -1) return dp[pos][sum][pre][cnt];
	long long res = 0;
	double avg = 1.0 * sum / (pos-1);
	
	if(a[pos] == -1) {
		for(int j = 0; j <= avg; j++) {
			if(j < pre && cnt == 1) continue;
			res = (res + dfs(pos+1, sum+j, j, j<pre?1:0)) % mod;
		}
	}
	else {
		if((a[pos] < pre && cnt == 1) || a[pos] > avg) return 0;
		res = (res + dfs(pos+1, sum+a[pos], a[pos], a[pos]<pre?1:0)) % mod;
	}
	
	return dp[pos][sum][pre][cnt] = res;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	long long ans = 0;
	if(a[1] == -1) {
		for(int i = 0; i <= 40; i++) {
			ans = (ans + dfs(2, i, i, 0)) % mod;
		}
	}
	else {
		ans = (ans + dfs(2, a[1], a[1], 0)) % mod;
	}
	
	printf("%lld\n", ans);
}