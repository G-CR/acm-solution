#include <bits/stdc++.h>
using namespace std;

int n, a, b;
int k[203];
struct node {
	int step;
	int now;
	node(int s, int p) {step=s;now=p;}
};
queue <node> q;
bool vis[203];

int bfs() {
	while(!q.empty()) q.pop();
	q.push(node(0, a)); vis[a] = 1;
	while(!q.empty()) {
		node t = q.front(); q.pop();
		if(t.now == b) return t.step;
		if(!vis[t.now+k[t.now]]&&t.now+k[t.now] <= n) vis[t.now+k[t.now]]=1,q.push(node(t.step+1, t.now+k[t.now]));
		if(!vis[t.now-k[t.now]]&&t.now-k[t.now] >= 1) vis[t.now-k[t.now]]=1,q.push(node(t.step+1, t.now-k[t.now]));
	}
	return -1;
}

int main() {
	while(~scanf("%d", &n)) {
		if(n == 0) break;
		memset(vis, 0, sizeof(vis));
		scanf("%d %d", &a, &b);
		for(int i = 1;i <= n; i++) scanf("%d", &k[i]);
		printf("%d\n", bfs());
	}
}