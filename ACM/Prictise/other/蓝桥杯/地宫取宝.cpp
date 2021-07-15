#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;
int n, m, k;
int a[55][55];
long long dp[55][55][20][15];

long long dfs(int x, int y, int cnt, int ma) {
	if(dp[x][y][cnt][ma] != -1) return dp[x][y][cnt][ma];
	if(x == n && y == m) {
		if(cnt == k || (a[x][y] > ma && cnt == k-1)) return 1;
		else return 0;
	}
	
	long long res = 0;
	if(ma < a[x][y] && cnt < k) {
		if(x+1 <= n)
			res = (res + dfs(x+1, y, cnt+1, a[x][y])) % mod;
		if(y+1 <= m)
			res = (res + dfs(x, y+1, cnt+1, a[x][y])) % mod;
	}
	if(x+1 <= n)
		res = (res + dfs(x+1, y, cnt, ma)) % mod;
	if(y+1 <= m)
		res = (res + dfs(x, y+1, cnt, ma)) % mod;
	
	return dp[x][y][cnt][ma] = res;
}

int main() {
	memset(dp, -1, sizeof dp);
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	printf("%lld\n", dfs(1, 1, 0, -1));
}