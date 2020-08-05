#include <iostream>
#include <queue>
using namespace std;

struct node1 {
	int u, v, w;
}edge[2005];
struct node {
	int num, s;
	node(int id, int step) {
		num = id; s = step;
	}
	bool operator < (const node&o) const {
		return o.s < s;
	}
};
int t, n;
int dist[1005];
vector <int> g[2005], d[2005];

int main() {
	scanf("%d %d", &t, &n);
	for(int i = 1;i <= t; i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
		g[edge[i].u].push_back(edge[i].v); g[edge[i].v].push_back(edge[i].u);
		d[edge[i].u].push_back(edge[i].w); d[edge[i].v].push_back(edge[i].w);
	}
	for(int i = 1;i <= n; i++) dist[i] = 1e9;
	priority_queue <node> q;
	q.push(node(1, 0)); dist[1] = 0;
	while(!q.empty()) {
		node k = q.top(); q.pop();
		if(k.s > dist[k.num]) continue;
		for(int i = 0;i < g[k.num].size(); i++) {
			int poi = g[k.num][i];
			if(dist[poi] > k.s + d[k.num][i]) {
				dist[poi] = k.s + d[k.num][i];
				q.push(node(poi, dist[poi]));
			}
		}
	}
	
	printf("%d\n", dist[n]);
}