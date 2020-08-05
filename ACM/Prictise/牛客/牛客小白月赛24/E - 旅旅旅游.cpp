#include <bits/stdc++.h>
using namespace std;

struct node1 {
	long long num, step;
	node1(int u, long long s) {
		num = u; step = s;
	}
	bool operator < (const node1&o) const {
		return o.step < step;
	}
};
struct node2 {
	int u, v, w;
}edge[500005];
int n, m, fa[100005];
long long dist[2][100005];
vector <int> poi[100005], len[100005];
priority_queue <node1> q;

int find(int x) {
	if(fa[x] == x) return x;
	else return fa[x] = find(fa[x]);
}

void dijkstra(bool a, int sta) {
	for(int i = 1;i <= n; i++) dist[a][i] = 1e18;
	dist[a][sta] = 0;
	q.push(node1(sta, 0));
	while(!q.empty()) {
		node1 t = q.top(); q.pop();
		if(t.step > dist[a][t.num]) continue;
		for(int i = 0;i < poi[t.num].size(); i++) {
			int k = poi[t.num][i];
			if(dist[a][k] > t.step + len[t.num][i]) {
				dist[a][k] = t.step + len[t.num][i];
				q.push(node1(k, dist[a][k]));
			}
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) fa[i] = i;
	for(int i = 1;i <= m; i++) {
		scanf("%d %d %d", &edge[i].u, &edge[i].v, &edge[i].w);
		poi[edge[i].u].push_back(edge[i].v); poi[edge[i].v].push_back(edge[i].u);
		len[edge[i].u].push_back(edge[i].w); len[edge[i].v].push_back(edge[i].w);
	}
	dijkstra(0,1); dijkstra(1, n);
	long long ans = dist[0][n];
	
	for(int i = 1;i <= m; i++) {
		if(dist[0][edge[i].u]+edge[i].w+dist[1][edge[i].v]==ans || dist[0][edge[i].v]+edge[i].w+dist[1][edge[i].u]==ans) continue;
		int u = find(edge[i].u);
		int v = find(edge[i].v);
		if(u != v) fa[u] = v;
	}
	
	bool ok = 1;
	for(int i = 2;i <= n; i++) {
		if(find(1) != find(i)) {
			ok = 0;
			break;
		}
	}
	if(ok) puts("YES");
	else puts("NO");
}