#include <bits/stdc++.h>
using namespace std;

int n, m;
int fa[200005];

struct node {
	int u, v, w;
	bool operator < (const node&o) const {
		return w < o.w;
	}
} line[200005];

int fin(int x) {
	if(x == fa[x]) return x;
	return fa[x] = fin(fa[x]);
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) fa[i] = i;
	for(int i = 1;i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		line[i].u = u;
		line[i].v = v;
		line[i].w = w;
	}
	sort(line+1, line+1+m);
	int ans = 0;
	for(int i = 1;i <= m; i++) {
		int u = fin(line[i].u);
		int v = fin(line[i].v);
		if(u != v) {
			fa[u] = v;
			ans += line[i].w;
		}
	}
	
	int father = fin(1);
	for(int i = 1;i <= n; i++) {
		int f = fin(i);
		if(f != father) {
			ans = -1;
		}
	}
	
	printf("%d\n", ans);
}