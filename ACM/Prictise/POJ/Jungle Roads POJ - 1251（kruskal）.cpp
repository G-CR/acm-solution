#include <iostream>
#include <algorithm>
using namespace std;

int n, fa[30];
struct node {
	int u, v, w;
} line[100];

bool cmp(node a, node b) {
	return a.w < b.w;
}

int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

int main() {
	while(~scanf("%d", &n) && n) {
		for(int i = 0;i < 29; i++) fa[i] = i;
		int k = 0;
		for(int tt = 0;tt < n-1; tt++) {
			char fir, sec;
			int mon, num;
			scanf(" %c %d", &fir, &num);
			while(num--) {
				scanf(" %c %d", &sec, &mon);
				line[++k].u = fir-'A'+1;
				line[k].v = sec-'A'+1;
				line[k].w = mon;
			}
		}
		sort(line+1, line+1+k, cmp);
//		for(int i = 1;i <= k; i++) cout << line[i].w << " ";		
		int ans = 0, cnt = 1;
		for(int i = 1;i <= k; i++) {
			int u = find(line[i].u);
			int v = find(line[i].v);
			if(u == v) continue;
			fa[u] = v;
			ans += line[i].w; 
			cnt++;
			if(cnt == n) break;
		}
		
		printf("%d\n", ans);
	}
}