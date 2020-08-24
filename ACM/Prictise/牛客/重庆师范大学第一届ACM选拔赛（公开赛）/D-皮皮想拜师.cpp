#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int n, m;
struct node {
	int pos, cnt;
	node(int a, int b) {pos = a; cnt = b;}
};
queue <node> q;

int bfs() {
	bool vis[100005];
	memset(vis, 0, sizeof vis);
	q.push(node(n, 0)); vis[n] = 1;
	
	while(!q.empty()) {
		node t = q.front(); q.pop();
		vis[t.pos] = 1;
		if(t.pos == m) return t.cnt;
		if(2*t.pos <= maxn && !vis[2*t.pos]) q.push(node(2*t.pos, t.cnt+1));
		if(t.pos+1 <= maxn && !vis[t.pos+1]) q.push(node(t.pos+1, t.cnt+1));
		if(t.pos-1 >= 1 && !vis[t.pos-1]) q.push(node(t.pos-1, t.cnt+1));
	}
}

int main() {
	scanf("%d %d", &m, &n);
	printf("%d\n", bfs());
}