#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

int n;
double x[202], y[202];
double mp[202][202];
double dist[202];
int vis[202];
struct node {
	int num, s;
	node(int id, double step) {
		num = id; s = step;
	}
	bool operator < (const node&o) const {
		return o.s < s;
	}
};

double dis(double x1, double y11, double x2, double y2) {
	return sqrt((x1-x2)*(x1-x2)+(y11-y2)*(y11-y2));
}

void dijkstra(int sta) {
	memset(vis, 0, sizeof(vis));
	for(int i = 1;i <= n; i++) dist[i] = 1e9;
	priority_queue <node> q;
	q.push(node(sta, 0)); dist[sta] = 0;
	
	while(!q.empty()) {
		node t = q.top(); q.pop();
		if(vis[t.num]) continue;
		vis[t.num] = 1;
		for(int i = 1;i <= n; i++) {
			if(dist[i] > max(dist[t.num], mp[t.num][i])) {
				dist[i] = max(dist[t.num], mp[t.num][i]);
				q.push(node(i, dist[i]));
			}
		}
	}
}

int main() {
	int _ = 0;
	while(~scanf("%d", &n) && n) {
		for(int i = 1;i <= n; i++) {
			scanf("%lf %lf", &x[i], &y[i]);
		}
		for(int i = 1;i <= n; i++) for(int j = 1;j <= n; j++) mp[i][j] = 1e9;
		for(int i = 1;i <= n; i++) {
			for(int j = i+1;j <= n; j++) {
				mp[i][j] = mp[j][i] = dis(x[i], y[i], x[j], y[j]);
			}
		}
		
		dijkstra(1);
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",++_, dist[2]);
	}
}