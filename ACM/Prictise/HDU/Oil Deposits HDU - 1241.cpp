#include <bits/stdc++.h>
using namespace std;

int m, n, vis[105][105];
char mp[105][105];
struct Node {
	int x, y;
}node, t;
queue <Node> q;


void bfs() {
	while(!q.empty()) {
		node = q.front(); q.pop();
		for(int i = -1;i <= 1; i++) {
			for(int j = -1;j <= 1; j++) {
				if(node.x+i < 1 || node.x+i > m || node.y+j < 1 || node.y+j > n || vis[node.x+i][node.y+j]) continue;
				if(mp[node.x+i][node.y+j] == '@') {
					vis[node.x+i][node.y+j] = 1;
					t.x = node.x+i; t.y = node.y+j;
					q.push(t);
				}
			}
		}
	}
}

int main() {
	while(~scanf("%d %d", &m, &n)) {
		if(m == 0 || n == 0) break;
		memset(vis, 0, sizeof(vis));
		for(int i = 1;i <= m; i++) {
			for(int j = 1;j <= n; j++) {
				scanf(" %c", &mp[i][j]);
			}
		}
		
		
		int ans = 0;
		for(int i = 1;i <= m; i++) {
			for(int j = 1;j <= n; j++) {
				if(mp[i][j] == '@' && !vis[i][j]) {
					vis[i][j] = 1;
					node.x = i; node.y = j;
					q.push(node);
					bfs();
					ans++;
				}
				
			}
		}
		printf("%d\n", ans);
	}
}