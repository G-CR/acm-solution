#include <iostream>
#include <algorithm>
using namespace std;

int n, fa[105];
struct node {
	int u, v, w;
	bool operator < (const node&o) const {
		return w < o.w;
	}
} line[10004];

int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

int main() {
	while(~scanf("%d", &n)) {
		int mon, k = 0;
		for(int i = 1;i <= n; i++) {
			fa[i] = i;
			for(int j = 1;j <= n; j++) {
				scanf("%d", &mon);
				if(i == j) continue;
				line[++k].u = i;
				line[k].v = j;
				line[k].w = mon;
			}
		}
		sort(line+1, line+1+k);
		
		int ans = 0;
		for(int i = 1;i <= k; i++) {
			int u = find(fa[line[i].u]);
			int v = find(fa[line[i].v]);
			if(u != v) {
				ans += line[i].w;
				fa[u] = v;
			}
		}
		printf("%d\n", ans);
	}
}