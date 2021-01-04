#include <iostream>
#include <algorithm>
using namespace std;

int n, cnt;
struct node {
	int l, w, h;
} g[200];
int dp[200][200];

bool cmp(node a, node b) {
	if(a.l == b.l) {
		if(a.w == b.w) {
			return a.h > b.h;
		}
		return a.w > b.w;
	}
	return a.l > b.l;
}

int dfs(int pos, int pre) {
	if(pos == cnt+1) return 0;
	if(dp[pos][pre]) return dp[pos][pre];
	int ans1 = 0, ans2 = 0;
	if(g[pos].l < g[pre].l && g[pos].w < g[pre].w) 
		ans1 = dfs(pos+1, pos) + g[pos].h;
	ans2 = dfs(pos+1, pre);
	return dp[pos][pre] = max(ans1, ans2);
}

int main() {
	int cas = 0;
	while(~scanf("%d", &n) && n) {
		cnt = 0;
		for(int i = 1;i <= n; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			g[++cnt].l = a; g[cnt].w = b; g[cnt].h = c;
			g[++cnt].l = a; g[cnt].w = c; g[cnt].h = b;
			g[++cnt].l = b; g[cnt].w = a; g[cnt].h = c;
			g[++cnt].l = b; g[cnt].w = c; g[cnt].h = a;
			g[++cnt].l = c; g[cnt].w = a; g[cnt].h = b;
			g[++cnt].l = c; g[cnt].w = b; g[cnt].h = a;
		}
		sort(g+1, g+1+cnt, cmp);
		for(int i = 1;i <= cnt; i++) {
			for(int j = 1;j <= cnt; j++) {
				dp[i][j] = 0;
			}
		}
		int ans = 0;
		for(int i = 1;i <= cnt; i++) {
			ans = max(ans, dfs(i, i)+g[i].h);
		}
		printf("Case %d: maximum height = %d\n", ++cas, ans);
	}
}