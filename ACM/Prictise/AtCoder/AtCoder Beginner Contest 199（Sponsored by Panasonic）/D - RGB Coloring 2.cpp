#include <bits/stdc++.h>
using namespace std;

int n, m;
vector <int> g[30], a;
int col[30];
bool vis[30];

void dfs(int p) {
	a.push_back(p);
	vis[p] = 1;
	for(int i: g[p]) {
		if(vis[i]) continue;
		dfs(i);
	}
}

bool check(int p, int c) {
	for(int i: g[p]) {
		if(col[i] == c) return 0;
	}
	return 1;
}

int dfss(int p) {
	if(p == a.size()) return 1;
	long long res = 0;
	for(int i = 1; i <= 3; i++) {
		if(check(a[p], i)) {
			col[a[p]] = i;
			res += dfss(p+1);
			col[a[p]] = 0;
		}
	}
	return res;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		int u, v; scanf("%d %d", &u, &v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	long long ans = 1;
	for(int i = 1; i <= n; i++) {
		if(vis[i]) continue;
		dfs(i);
		ans *= dfss(0);
		a.clear();
	}
	
	printf("%lld\n", ans);
}