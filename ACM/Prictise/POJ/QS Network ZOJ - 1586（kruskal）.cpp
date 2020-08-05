#include <bits/stdc++.h>
using namespace std;

int _, n, cost[1005], fa[1005];
struct node {
	int u, v, w;
} line[1000005];

bool cmp(node a, node b) {
	return a.w < b.w;
}

int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &cost[i]);
			fa[i] = i;
		} 
		int k = 0, mon;
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= n; j++) {
				scanf("%d", &mon);
				if(i == j) continue;
				line[++k].u = i;
				line[k].v = j;
				line[k].w = mon+cost[line[k].u]+cost[line[k].v];
			}
		}
		sort(line+1, line+1+k, cmp);
		
		int ans = 0, cnt = 1;
		for(int i = 1;i <= k; i++) {
			int u = find(fa[line[i].u]);
			int v = find(fa[line[i].v]);
			
			if(u == v) continue;
			ans += line[i].w;
			cnt++;
			fa[u] = v;
			if(cnt == n) break;
		}
		
		printf("%d\n", ans);
	}
}