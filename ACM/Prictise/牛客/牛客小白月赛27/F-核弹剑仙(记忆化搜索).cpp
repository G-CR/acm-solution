#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> g[1003];
set <int> st[1003];

set <int> dfs(int pos) {
	set <int> t;
	if(g[pos].size() == 0) return t;
	if(!st[pos].empty()) return st[pos];
	
	for(int i = 0;i < g[pos].size(); i++) {
		st[pos].insert(g[pos][i]);
		t = dfs(g[pos][i]);
		st[pos].insert(t.begin(), t.end());
	}
	return st[pos];
}

int main() {
	scanf("%d %d", &n, &m);
	int u, v;
	
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &u, &v);
		g[v].push_back(u);
	}
	
	for(int i = 1;i <= n; i++) {
		set <int> res = dfs(i);
		printf("%lu\n", res.size());
	}
}