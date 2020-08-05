#include <bits/stdc++.h>
using namespace std;

int n, k[100005], son[100005], ans;
vector <int> g[100005];

void dfs(int x) {
	for(int i = 0;i < g[x].size(); i++) {
		int u = g[x][i];
		dfs(u);
		k[x] = max(k[x], k[u]-1);
		son[x] = max(son[x], son[u]-1);
	}
	if(son[x] == 0) {
		ans++;
		son[x] = k[x];
	}
}

int main() {
	scanf("%d", &n);
	int fa;
	for(int i = 2;i <= n; i++) {
		scanf("%d", &fa);
		g[fa].push_back(i);
	}
	for(int i = 1;i <= n; i++) scanf("%d", &k[i]);
	
	dfs(1);
	printf("%d\n", ans);
}