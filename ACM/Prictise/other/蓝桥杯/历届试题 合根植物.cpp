#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int fa[1000006];
bool vis[1000006];
int fin(int x) {
	if(fa[x] == x) return x;
	return fa[x] = fin(fa[x]);
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	int tot = n * m;
	for(int i = 1; i <= tot; i++) fa[i] = i;
	
	for(int i = 1; i <= k; i++) {
		int u, v; scanf("%d %d", &u, &v);
		int fu = fin(u), fv = fin(v);
		if(fu == fv) continue;
		fa[fu] = fv;
	}
	
	int ans = 0;
	for(int i = 1; i <= tot; i++) {
		int f = fin(i);
		if(vis[f]) continue;
		vis[f] = 1;
		ans++;
	}
	
	printf("%d\n", ans);
	return 0;
}