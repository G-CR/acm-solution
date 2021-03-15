#include <bits/stdc++.h>
using namespace std;

int n, t;
int num[103], v[103], to[103];
int dp[103][1003];

void read() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &num[i]);
	}
	for(int i = 1;i <= n; i++) {
		scanf("%d", &v[i]);
	}
	for(int i = 2;i <= n; i++) {
		scanf("%d", &to[i]);
	}
	scanf("%d", &t);
}

int dfs(int pos, int now) {
	if(now > t || pos > n) return 0;
	if(dp[pos][now]) return dp[pos][now];
	int res = 0, sum = 0;
	res = max(res, dfs(pos+1, now+to[pos+1]));
	for(int cnt = num[pos], tim = 1; cnt > 0; cnt -= v[pos], tim++) {
		sum += cnt;
		if(now+tim <= t)
			res = max(res, dfs(pos+1, now+tim+to[pos+1]) + sum);
	}
	return dp[pos][now] = res;
}

int main() {
	read();
	printf("%d\n", dfs(1, 0));
}