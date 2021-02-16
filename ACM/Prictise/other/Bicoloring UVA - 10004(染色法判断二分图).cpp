#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> g[203];
int col[203];

bool dfs(int pos, int c) {
	col[pos] = c;
	for(int i = 0;i < g[pos].size(); i++) {
		int now = g[pos][i];
		if(!col[now]) {
			bool nice = dfs(now, -c);
			if(!nice) return 0;
		}
		else if(col[now] == c) return 0;
	}
	
	return 1;
}

int main() {
	while(~scanf("%d", &n) && n) {
		scanf("%d", &m);
		for(int i = 1;i <= n; i++) {
			col[i] = 0;
			g[i].clear();
		}
		
		for(int i = 1;i <= m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		
		bool ok;
		for(int i = 1;i <= n; i++) {
			if(!col[i]) {
				ok = dfs(i, 1);
				if(!ok) {
					break;
				}
			}
		}
		
		if(ok) puts("BICOLORABLE.");
		else puts("NOT BICOLORABLE.");
	}
}