#include <bits/stdc++.h>
using namespace std;

int n, m;
int price[30004], imp[30004];
int dp[30][30004][2];

int dfs(int pos, int sheng, bool qu) {
	if(pos == m+1) {
		return 0;
	}
	if(dp[pos][sheng][qu]) return dp[pos][sheng][qu];
//	printf("n = %d pos = %d\n", n, pos);
	int ans1 = 0, ans2 = 0;
	if(qu && sheng >= price[pos]) {
		ans1 = max(dfs(pos+1, sheng-price[pos], 0), dfs(pos+1, sheng-price[pos], 1)) + price[pos]*imp[pos];
	}
	else if(!qu) {
		ans2 = max(dfs(pos+1, sheng, 0), dfs(pos+1, sheng, 1));
	}
	return dp[pos][sheng][qu] = max(ans1, ans2);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &price[i], &imp[i]);
	}
	printf("%d\n", max(dfs(1,n,1), dfs(1,n,0)));
}