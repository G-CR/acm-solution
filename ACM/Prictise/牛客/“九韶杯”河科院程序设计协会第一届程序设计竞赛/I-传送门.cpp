#include <bits/stdc++.h>
using namespace std;

int n, m;

int fa[5003];
int fin(int x) {
	if(fa[x] == x) return x;
	return fa[x] = fin(fa[x]);
}

struct node {
	int u, v, w;
} p[100005];

bool cmp(node a, node b) {
	return a.w < b.w;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 1; i <= m; i++) {
		int u, v, w; scanf("%d %d %d", &u, &v, &w);
		p[i] = {u, v, w};
	}
	sort(p+1, p+1+m, cmp);
	
	int ans = 0;
	for(int i = 1; i <= m; i++) {
		int fu = fin(p[i].u);
		int fv = fin(p[i].v);
		if(fu == fv) continue;
		fa[fu] = fv;
		ans = max(ans, p[i].w);
	}
	
	int f = fin(1);
	for(int i = 2; i <= n; i++) {
		int r = fin(i);
		if(r != f) {
			ans = -1;
			break;
		}
	}
	
	printf("%d\n", ans);
	
}