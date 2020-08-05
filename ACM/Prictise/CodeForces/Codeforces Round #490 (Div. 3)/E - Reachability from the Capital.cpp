#include <bits/stdc++.h>
using namespace std;

int n, m, s, cnt;
vector <int> g[5005];
bool vis[5005], ok[5005];

void dfs1(int u) {
	ok[u] = 1;
	for(auto to: g[u]) {
		if(!ok[to]) dfs1(to);
	}
}

void dfs2(int u) {
	vis[u] = 1;
	++cnt;
	for(auto to: g[u]) {
		if(!ok[to] && !vis[to]) dfs2(to);
	}
}


int main() {
	scanf("%d %d %d", &n, &m, &s); s--;
	int u, v;
	for(int i = 0;i < m; i++) {
		scanf("%d %d", &u, &v); u--; v--;
		g[u].push_back(v);
	}
	
	dfs1(s);
	
	vector<pair<int, int> > val;
	for(int i = 0;i < n; i++) {
		if(!ok[i]) {
			cnt = 0;
			memset(vis, 0, sizeof(vis));
			dfs2(i);
			val.push_back(make_pair(cnt, i));
		}
	}
	
	sort(val.begin(), val.end());
	reverse(val.begin(), val.end());
	
	int ans = 0;
	for(auto it: val) {
		if(!ok[it.second]) {
			ans++;
			dfs1(it.second);
		}
	}
	
	printf("%d\n", ans);
}