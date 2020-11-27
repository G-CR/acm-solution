#include <bits/stdc++.h>
using namespace std;

int n, m, fa[500005];
struct Line {
	int u, v, w;
} g[500005];
bool cmp(Line a, Line b) {return a.w > b.w;}
int fin(int x) {
	if(fa[x] == x) return x;
	return fa[x] = fin(fa[x]);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) fa[i] = i;
	for(int i = 1;i <= m; i++) {
		scanf("%d %d %d", &g[i].u, &g[i].v, &g[i].w);
	}
	
	sort(g+1, g+1+m, cmp);
	
	long long ans = 0;
	for(int i = 1;i <= m; i++) {
		int u = fin(g[i].u), v = fin(g[i].v);
		if(u == v) continue;
		ans += g[i].w;
		fa[u] = v;
	}
	
	printf("%lld\n", ans);
}