#include <bits/stdc++.h>
using namespace std;

int _, n, fa[105];
struct point {
	int x, y;
} poi[105];
struct node {
	int u, v;
	double w;
	bool operator < (const node&o) const {
		return w < o.w;
	}
} line[10004];

double dis(point a, point b) {
	double x = a.x-b.x;
	double y = a.y-b.y;
	return sqrt(x*x+y*y);
}
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			fa[i] = i;
			scanf("%d %d", &poi[i].x, &poi[i].y);
		}
		
		int k = 0;
		for(int i = 1;i <= n; i++) {
			for(int j = i+1;j <= n; j++) {
				double mon = dis(poi[i], poi[j]);
				if(mon >= 10 && mon <= 1000) {
					line[++k].u = i;
					line[k].v = j;
					line[k].w = mon;
				}
			}
		}
		
		sort(line+1, line+1+k);
		double ans = 0;
		int cnt = 1;
		for(int i = 1;i <= k; i++) {
			int u = find(line[i].u);
			int v = find(line[i].v);
			if(u != v) {
				fa[u] = v;
				cnt++;
				ans += line[i].w;
			}
		}
		
		bool ok = 1;
		if(cnt == n) printf("%.1lf\n", ans*100);
		else puts("oh!");
	}
}