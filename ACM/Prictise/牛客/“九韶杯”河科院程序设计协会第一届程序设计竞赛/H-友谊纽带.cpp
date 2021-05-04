#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> g[2003];

int fa[2003];
int fin(int x) {
	if(x == fa[x]) return x;
	return fa[x] = fin(fa[x]);
}

bool nice() {
	int f = fin(1);
	for(int i = 2; i <= n; i++) {
		int h = fin(i);
		if(f != h) return 0;
	}
	return 1;
}

int bfs(int s) {
	queue <pair <int, int> > q;
	bool vis[2003]; memset(vis, 0, sizeof(vis));
	q.push({s, 0});
	int ma = 0;
	while(!q.empty()) {
		auto t = q.front(); q.pop();
		int p = t.first, w = t.second;
		int son = 0;
		for(int i : g[p]) {
			if(vis[i]) continue;
			vis[i] = 1; son++;
			q.push({i, w+1});
		}
		if(!son) ma = max(ma, w);
	}
	
	return ma;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		int u, v; scanf("%d %d", &u, &v);
		
		int fu = fin(u), fv = fin(v);
		if(fu != fv) fa[fu] = fv;
		
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	if(!nice()) return puts("-1"), 0;
	
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, bfs(i));
	}
	printf("%d\n", ans);
}