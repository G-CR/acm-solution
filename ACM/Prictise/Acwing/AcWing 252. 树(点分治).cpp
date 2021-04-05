#include <bits/stdc++.h>
using namespace std;
const int N = 1e4+10;
int n, k, sz[N], mx[N], vis[N], rt, minn, ans;
vector <pair <int, int> > g[N];

void get_rt(int u, int f) {
	sz[u] = 1, mx[u] = 0;
	for(auto i: g[u]) {
		int to = i.first;
		int w = i.second;
		if(to == f || vis[to]) continue;
		get_rt(to, u);
		sz[u] += sz[to];
		mx[u] = max(mx[u], sz[to]);
	}
	
	mx[u] = max(mx[u], n - sz[u]);
	if(minn > mx[u]) {
		minn = mx[u];
		rt = u;
	}
}

vector <int> all, cat;

void dfs(int u, int f, int deep) {
	cat.push_back(deep);
	for(auto i: g[u]) {
		int to = i.first;
		int w = i.second;
		if(to == f || vis[to]) continue;
		dfs(to, u, deep + w);
	}
}

void cal() {
	for(int i: cat) {
		int p = upper_bound(all.begin(), all.end(), k - i) - all.begin();
		if(i <= k) ans++;
		ans += p;
	}
	
	for(int i: cat) all.push_back(i);
	sort(all.begin(), all.end());
}

void work(int u) {
	all.clear();
	for(auto i: g[u]) {
		int to = i.first;
		int w = i.second;
		if(vis[to]) continue;
		cat.clear();
		dfs(to, u, w);
		
		cal();
	}
}

void solve(int u) {
	vis[u] = 1;
	work(u);
	for(auto i: g[u]) {
		int to = i.first;
		if(vis[to]) continue;
		n = sz[to];
		minn = n + 1;
		get_rt(to, 0);
		get_rt(rt, 0);
		`
		solve(rt);
	}
}

int main() {
	while(~scanf("%d %d", &n, &k) && n) {
		for(int i = 0; i <= n; i++) {
			g[i].clear();
			vis[i] = 0;
		}
		for(int i = 1; i < n; i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w); u++, v++;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
		ans = 0;
		minn = n + 1;
		get_rt(1, 0);
		get_rt(rt, 0);
		
		solve(rt);
		
		printf("%d\n", ans);
	}
}