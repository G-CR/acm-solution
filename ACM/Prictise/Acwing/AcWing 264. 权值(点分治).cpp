#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+10;
int n, k, sz[N], mx[N], vis[N], rt, minn, ans = 1e9;
vector <pair <int, int> > g[N];

void get_rt(int u, int f) {
	mx[u] = 0; sz[u] = 1;
	for(auto i: g[u]) {
		int to = i.first;
		int w = i.second;
		if(vis[to] || to == f) continue;
		get_rt(to, u);
		mx[u] = max(mx[u], sz[to]);
		sz[u] += sz[to];
	}

	mx[u] = max(mx[u], n - sz[u]);
	if(minn > mx[u]) {
		minn = mx[u];
		rt = u;
	}
}

int all[1000006], cat[1000006];
vector <int> rall, rcat;

void dfs(int u, int f, int deep, int cnt) {
	if(deep > k) return;
	if(!cat[deep]) cat[deep] = 1e9;
	cat[deep] = min(cat[deep], cnt);
	rcat.push_back(deep);
	
	for(auto i: g[u]) {
		int to = i.first;
		int w = i.second;
		if(vis[to] || to == f) continue;
		dfs(to, u, deep + w, cnt + 1);
	}
}


void clear_all() {
	for(int i: rall) all[i] = 0;
	rall.clear();
}

void clear_cat() {
	for(int i: rcat) cat[i] = 0;
	rcat.clear();
}

void work(int u) {
	clear_all();
	
	for(auto i: g[u]) {
		int to = i.first;
		int w = i.second;
		if(vis[to]) continue;
		clear_cat();
		dfs(to, 0, w, 1);
		
		
		for(auto j: rcat) {
			int nd = k - j;
			if(all[nd]) {
				ans = min(ans, all[nd] + cat[j]);
			}
		}
		
		if(cat[k]) ans = min(ans, cat[k]);
		
		for(auto j: rcat) {
			if(!all[j]) {
				all[j] = cat[j];
				rall.push_back(j);
			} 
			else all[j] = min(all[j], cat[j]);
		}
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
		
		solve(rt);
	}
}

int main() {
	scanf("%d %d", &n, &k);
	for(int i = 1; i < n; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w); 
		u++, v++;
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	
	minn = n + 1;
	get_rt(1, 0);
	get_rt(rt, 0);
	
	solve(rt);
	
	printf("%d\n", ans==1e9?-1:ans);
}