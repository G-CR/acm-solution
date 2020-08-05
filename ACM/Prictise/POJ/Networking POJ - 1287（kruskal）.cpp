#include <iostream>
#include <algorithm>
using namespace std;

int P, R, fa[55];
struct node {
	int u, v, w;
} line[100000];

bool cmp(node a, node b) {
	return a.w < b.w;
}

int find(int x) {
	return fa[x] == x?x:fa[x] = find(fa[x]);
}

int main() {
	while(~scanf("%d", &P) && P) {
		for(int i = 1;i <= P; i++) fa[i] = i;
		scanf("%d", &R);
		int fir, sec, mon, k = 0;
		while(R--) {
			scanf("%d %d %d", &fir, &sec, &mon);
			line[++k].u = fir;
			line[k].v = sec;
			line[k].w = mon;
		}
		
		sort(line+1, line+1+k, cmp);
		
		int cnt = 1, ans = 0;
		for(int i = 1;i <= k; i++) {
			int u = find(line[i].u);
			int v = find(line[i].v);
			if(u == v) continue;
			fa[u] = v;
			ans += line[i].w;
			cnt++;
			if(cnt == P) break;
		}
		
		printf("%d\n", ans);
	}
}