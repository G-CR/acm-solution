#include <bits/stdc++.h>
using namespace std;

struct node {
	int to, val, next;
} e[20004];
long long ans;
int n, tot, _, head[10004];

void addEdge(int u, int v, int w) {
	tot++;
	e[tot].to = v;
	e[tot].val = w;
	e[tot].next = head[u];
	head[u] = tot;
}

int dfs(int u, int fa, int w) {
	int cnt = 1;
	for(int i = head[u]; i != 0; i = e[i].next) {
		if(e[i].to != fa) cnt += dfs(e[i].to, u, e[i].val);
	}
	if(cnt&1) ans += w;
	return cnt;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		ans = 0; tot = 0;
		int u, v, w;
		memset(head, 0, sizeof(head));
		scanf("%d", &n);
		for(int i = 1;i < n; i++) {
			scanf("%d %d %d", &u, &v, &w);
			addEdge(u, v, w);
			addEdge(v, u, w);
		}
		
//		for(int i = 1;i <= n; i++) {
//			printf("%d: ", i);
//			for(int j = head[i]; j != 0; j = e[j].next) {
//				printf("%d ", e[j].to);
//			}
//			puts("");
//		}
		
		dfs(1, 0, 0);
		printf("%lld\n", ans);
	}
}