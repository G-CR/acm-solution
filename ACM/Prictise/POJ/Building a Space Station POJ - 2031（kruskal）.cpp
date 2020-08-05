#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int n, fa[105];
struct node {
	double x, y, z, r;
} poi[105];

struct GCR {
	int u, v;
	double w;
} line[10005];

double dist(node a, node b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}

bool cmp(GCR a, GCR b) {
	return a.w < b.w;
}

int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

int main() {
	while(~scanf("%d", &n) && n) {
		for(int i = 1;i <= n; i++) fa[i] = i;
		for(int i = 1;i <= n; i++) {
			scanf("%lf %lf %lf %lf", &poi[i].x, &poi[i].y, &poi[i].z, &poi[i].r);
		}
		
		int k = 0;
		for(int i = 1;i <= n; i++) {
			for(int j = i+1;j <= n; j++) {
				double dis = dist(poi[i], poi[j]);
//				cout << "i = " << i << " j = " << j << " dis = " << dis << " " << (dis <= poi[i].r+poi[j].r) <<endl;
				int u = find(fa[i]);
				int v = find(fa[j]);
				if(dis <= poi[i].r+poi[j].r) {
					if(u == v) continue;
					fa[u] = v;
				}
				else {
					line[++k].u = i;
					line[k].v = j;
					line[k].w = dis-(poi[i].r+poi[j].r);
				}
			}
		}
		
		sort(line+1, line+1+k, cmp);
		
		int cnt = 1;
		double ans = 0;
		for(int i = 1;i <= k; i++) {
			int u = find(fa[line[i].u]);
			int v = find(fa[line[i].v]);
			if(u == v) continue;
			fa[u] = v;
//			cout << "u = " << u << " v = " << v << endl;
			ans += line[i].w;
			cnt++;
			if(cnt == n) break;
		}
		
		printf("%.3lf\n", ans);
	}
}