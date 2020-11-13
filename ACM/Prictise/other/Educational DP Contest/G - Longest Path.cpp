#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[100005];
vector<int> g[100005];

void dfs(int pos) {
	if(dp[pos]) return;
	for(auto i:g[pos]) {
		dfs(i);
		dp[pos] = max(dp[pos], dp[i] + 1);
	}
}

int main() {
	memset(dp, 0, sizeof(dp));
	scanf("%d %d", &n, &m);
	int u, v;
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
	}
	
	for(int i = 1;i <= n; i++) {
		dfs(i);
	} 
//	for(int i = 1;i <= n; i++) printf("dp[%d] = %d\n", i, dp[i]);
	
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		ans = max(ans, dp[i]);
	}
	
	printf("%d\n", ans);
}


/*

#include <bits/stdc++.h>
using namespace std;

int n, m;
int dp[100005];
vector <int> g[100005];

int dfs(int pos) {
	if(dp[pos]) return dp[pos];
	for(auto i:g[pos]) {
		dp[pos] = max(dp[pos], dfs(i)+1);
	}
	return dp[pos];
}

int main() {
	scanf("%d %d", &n, &m);
	int u, v;
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
	}
	memset(dp, 0, sizeof(dp));
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		printf("i = %d sum = %d\n", i, dfs(i));
		ans = max(ans, dfs(i));
	} 
	for(int i = 1;i <= n; i++) printf("%d ", dp[i]); puts("");
	printf("%d\n", ans);
}

*/