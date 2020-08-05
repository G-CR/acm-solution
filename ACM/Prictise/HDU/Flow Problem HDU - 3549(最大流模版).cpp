#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll inf = 1e18, N = 20, M = 3000;

struct node {
	int to, next;
	ll w;
}edge[M];
ll maxflow;
int tot, head[N];
int n, m, s, t;
ll deep[N]; //层级数，其实应该是level
int now[M]; //当前弧优化
queue <int> q;
int _;

void addedge(int u, int v, int w) {
	edge[++tot].to = v; edge[tot].w = w; edge[tot].next = head[u]; head[u] = tot;
	edge[++tot].to = u; edge[tot].w = 0; edge[tot].next = head[v]; head[v] = tot;
}

bool bfs() {
	for(int i = 1;i <= n; i++) deep[i] = inf;
	while(!q.empty()) q.pop();
	q.push(s); deep[s] = 0; now[s] = head[s];
	
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(int i = head[u]; i; i = edge[i].next) {
			int v = edge[i].to;
			if(edge[i].w && deep[v] == inf) {
				q.push(v);
				now[v] = head[v];
				deep[v] = deep[u] + 1;
				if(v == t) return 1;
			}
		}
	}
	return 0;
}

//flow是整条增广路对最大流的贡献，rest是当前最小剩余容量，用rest去更新flow
ll dfs(int u, ll flow) {
	if(u == t) return flow;
	ll ans = 0;
	for(int i = now[u];i && flow; i = edge[i].next) {
		now[u] = i; //当前弧优化（避免重复遍历从x出发的不可拓展的边）
		int v = edge[i].to;
		if(edge[i].w && deep[v] == deep[u]+1) { //必须是下一层并且剩余容量大于0
			ll k = dfs(v, min(flow, edge[i].w)); //取最小
			if(!k) deep[v] = inf; //剪枝，去掉增广完毕的点
			
			edge[i].w -= k; //回溯时更新
			edge[i^1].w += k; //成对变换
			
			ans += k;
			flow -= k;
		}
	}
	
	return ans;
}

void dinic() {
	while(bfs())
		maxflow += dfs(s, inf);
}


int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d %d", &n, &m);
		tot = 1; maxflow = 0;
		memset(head, 0, sizeof(head));
		s = 1; t = n;
		
		for(int i = 1;i <= m; i++) {
			int u, v; ll w;
			scanf("%d %d %lld", &u, &v, &w);
			addedge(u, v, w);
		}
		dinic();
		printf("Case %d: ", ++cas);
		printf("%lld\n", maxflow);
	}
}