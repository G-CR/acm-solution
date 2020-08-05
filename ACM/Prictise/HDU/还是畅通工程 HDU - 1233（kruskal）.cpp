#include <bits/stdc++.h>
using namespace std;

int n, fir, sec, mon, fa[10000];
struct node {
	int u, v, w;
	bool operator < (const node&o) const {
		return w < o.w;
	}
} line[10000];
int find(int x) {return fa[x] == x?x:fa[x] = find(fa[x]);}

int main() {
	while(~scanf("%d", &n) && n) {
		int sum = n*(n-1)/2;
		for(int i = 1;i <= sum; i++) {
			fa[i] = i;
			scanf("%d %d %d", &fir, &sec, &mon);
			line[i].u = fir; 
			line[i].v = sec; 
			line[i].w = mon;
		}
		
		sort(line+1, line+1+sum);
		int ans = 0;
		for(int i = 1;i <= sum; i++) {
			int u = find(line[i].u);
			int v = find(line[i].v);
			if(u != v) {
				fa[u] = v;
				ans += line[i].w;
			}
		}
		printf("%d\n", ans);
	}
}