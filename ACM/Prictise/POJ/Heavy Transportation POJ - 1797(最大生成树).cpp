#include <iostream>
#include <algorithm>
using namespace std;

int _, n, m, fa[1005];
struct node {
	int u, v, w;
	bool operator < (const node&o) const {
		return w > o.w;
	}
} edge[1000006];

int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	scanf("%d", &_);
	for(int cas = 1;cas <= _; cas++) {
		int u, v, w;
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) fa[i] = i;
		for(int i = 1;i <= m; i++) {
			scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
		}
		sort(edge+1, edge+1+m);
//		for(int i = 1;i <= m; i++) printf("%d ", edge[i].w); puts("");
		
		int ans = 1e9;
		for(int i = 1;i <= m; i++) {
			int u = find(edge[i].u);
			int v = find(edge[i].v);
			if(u != v) {
				fa[u] = v;
				ans = min(ans, edge[i].w);
			}
			u = find(1); v = find(n);
			if(u == v) break;
		}
		printf("Scenario #%d:\n%d\n\n", cas, ans);
	}
}