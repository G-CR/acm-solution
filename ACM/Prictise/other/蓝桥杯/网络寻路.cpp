#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> g[10004];
bool vis[10004];

int dfs(int now, int sta, int cnt) {
	if(cnt == 3) {
		return 1;
	}
	int res = 0;
	for(int i = 0; i < g[now].size(); i++) {
		int to = g[now][i];
		if(to == sta && cnt == 2) {
			res++;
			continue;
		}
		if(!vis[to]) {
			vis[to] = 1;
			res += dfs(to, sta, cnt+1);
			vis[to] = 0;
		}
	}
	
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v); {
			g[u].push_back(v);
			g[v].push_back(u);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		vis[i] = 1;
		ans += dfs(i, i, 0);
		vis[i] = 0;
	}
	
	printf("%d\n", ans);
}