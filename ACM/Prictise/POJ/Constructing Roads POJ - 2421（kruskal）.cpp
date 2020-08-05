#include <iostream>
#include <algorithm>
using namespace std;

int n, q, fa[105];
struct node {
	int u, v, w;
} line[10000];

int find(int x) {
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

bool cmp(node a, node b) {
	return a.w < b.w;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) fa[i] = i;
	int mon, k = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= n; j++) {
			scanf("%d", &mon);
			if(i == j) continue;
			line[++k].u = i; 
			line[k].v = j; 
			line[k].w = mon;
		}
	}
	sort(line+1, line+1+k, cmp);
	
	int cnt = 1, fir, sec;
	scanf("%d", &q);
	while(q--) {
		scanf("%d %d", &fir, &sec);
		int u = find(fa[fir]);
		int v = find(fa[sec]);
		if(u != v) {
			fa[u] = v;
			cnt++;
		}
	}
	
	int ans = 0, u, v;
	for(int i = 1;i <= k; i++) {
		if(cnt == n) break;
		int u = find(fa[line[i].u]);
		int v = find(fa[line[i].v]);
		if(u == v) continue;
		fa[u] = v;
		ans += line[i].w;
		cnt++;
	}
	
	printf("%d\n", ans);
}