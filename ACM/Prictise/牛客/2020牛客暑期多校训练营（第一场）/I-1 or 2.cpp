#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
using namespace std;
struct EDGE {
	int to, w, next;
} edge[2000];
int cnt;
int head[2000];
int deep[2000];

void init() {
	cnt = 0;
	memset(head, -1, sizeof(head));
}

void addedge(int u, int v, int w) {
	edge[cnt].to=v; edge[cnt].w=w; edge[cnt].next=head[u]; head[u]=cnt++;
	edge[cnt].to=u; edge[cnt].w=0; edge[cnt].next=head[v]; head[v]=cnt++;
}

int bfs(int s, int t) {
	queue<int> q;
	memset(deep, 0, sizeof(deep));
	q.push(s);
	deep[s] = 1;
	int top;
	while(!q.empty()) {
		top = q.front();
		q.pop();
		for(int i = head[top];i+1; i = edge[i].next) {
			int v = edge[i].to;
			int w = edge[i].w;
			if(!deep[v]&&w) {
				deep[v] = deep[top]+1;
				q.push(v);
			}
		}
	}
	return deep[t];
}

int dfs(int s, int t, int inflow) {
	if(s==t) return inflow;
	int acflow=0;
	for(int i=head[s]; i+1; i=edge[i].next) {
		if(edge[i].w && deep[s]+1 == deep[edge[i].to]) {
			int x = dfs(edge[i].to,t,min(inflow, edge[i].w));
			if(x>0) {
				acflow+=x; inflow-=x;edge[i].w -= x; edge[i^1].w += x;
				if(!inflow) break;
			}
		}
	}
	if(!acflow) deep[s] = -2;
	return acflow;
}

int dinic(int s,int t) {
	int f = 0;
	while(bfs(s,t)) f += dfs(s,t,INF);
	return f;
}

int n, m, a, b;
int d[55];

int main() {
	while(~scanf("%d %d", &n, &m)) {
		init();
		int sum = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &d[i]);
			sum += d[i];
			addedge(0, i, d[i]);
		}
		
		int l = 1e9, r = 0;
		for(int i = 1;i <= m; i++) {
			scanf("%d %d", &a, &b);
			addedge(a, b+n, 1);
			l = min(l, b+n); r = max(r, b+n);
			addedge(b, a+n, 1);
			l = min(l, a+n); r = max(r, a+n);
		}
		
		int fin = r+1;
		for(int i = l;i <= r; i++) {
			addedge(i, fin, d[i-n]);
		}
		
		printf("%s\n", dinic(0, fin)==sum?"Yes":"No");
	}
}