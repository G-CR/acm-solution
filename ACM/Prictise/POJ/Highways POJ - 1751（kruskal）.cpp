#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Poi {
	int x, y;
} poi[800];
struct node {
	int u, v;
	double w;
	bool operator < (const node&o) const {
		return w < o.w;
	}
} line[700000];
int n, m, fa[800];

int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

double dis(Poi a, Poi b) {
	double x = a.x - b.x;
	double y = a.y - b.y;
	return sqrt(x*x + y*y);
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) fa[i] = i;
	for(int i = 1;i <= n; i++) scanf("%d %d", &poi[i].x, &poi[i].y);
	
	scanf("%d", &m);
	int fir, sec;
	while(m--) {
		scanf("%d %d", &fir, &sec);
		int u = find(fir);
		int v = find(sec);
		fa[u] = v;
	}
	
	int k = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = i+1;j <= n; j++) {
			line[++k].u = i; 
			line[k].v = j; 
			line[k].w = dis(poi[i], poi[j]);
		}
	}
	
	sort(line+1, line+1+k);
	for(int i = 1;i <= k; i++) {
		int u = find(line[i].u);
		int v = find(line[i].v);
		if(u != v) {
			fa[u] = v;
			printf("%d %d\n", line[i].u, line[i].v);
		}
		
	}
	return 0;
}