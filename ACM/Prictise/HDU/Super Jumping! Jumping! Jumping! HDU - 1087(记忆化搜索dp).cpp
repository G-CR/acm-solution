#include <iostream>
using namespace std;

int n;
int a[1003], dp[1003];

int dfs(int pos) {
	if(dp[pos]) return dp[pos];
	int ans = a[pos];
	for(int i = pos+1;i <= n; i++) {
		if(a[i] > a[pos]) {
			ans = max(ans, dfs(i)+a[pos]);
		}
	}
	return dp[pos] = ans;
}

int main() {
	while(~scanf("%d", &n) && n) {
		for(int i = 1;i <= n; i++) scanf("%d", &a[i]), dp[i] = 0;
		int ans = 0;
		for(int i = 1;i <= n; i++) {
			ans = max(ans, dfs(i));
		}
		printf("%d\n", ans);
	}
}