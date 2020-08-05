#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Poi {
	double x, y;
} poi[505];
struct node {
	int u, v;
	double w;
} line[250005];
int fa[505], _, s, p;

int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

bool cmp(node a, node b) {
	return a.w < b.w;
}

double dis(Poi a, Poi b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &s, &p);
		for(int i = 1;i <= p; i++) {
			fa[i] = i;
			scanf("%lf %lf", &poi[i].x, &poi[i].y);
		}
		
		int k = 0;
		for(int i = 1;i <= p; i++) {
			for(int j = i+1;j <= p; j++) {
				line[++k].u = i;
				line[k].v = j;
				line[k].w = dis(poi[i], poi[j]);
			}
		}
		
		sort(line+1, line+1+k, cmp);
//		for(int i = 1;i <= k; i++) cout << "line[i].w = " << line[i].w << endl;
		int cnt = 1;
		double ans;
		for(int i = 1;i <= k; i++) {
			int u = find(fa[line[i].u]);
			int v = find(fa[line[i].v]);
			if(u == v) continue;
			double t = line[i].w;
//			cout << "t = " << t << endl;
			fa[u] = v;
			cnt++;
			if(cnt == p-s+1) {
				ans = t;
				break;
			}
		}
		printf("%.2lf\n", ans);
	}
}