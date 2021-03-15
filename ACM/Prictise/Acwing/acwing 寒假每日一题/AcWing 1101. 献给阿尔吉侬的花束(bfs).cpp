#include <bits/stdc++.h>
using namespace std;

int _;
int n, m;
int stx, sty, edx, edy;
int tx[] = {0,0,1,-1};
int ty[] = {1,-1,0,0};
char a[202][202];
bool vis[202][202];
struct node {
	int x, y;
	int step;
};
queue <node> q;

int bfs() {
	vis[stx][sty] = 1;
	q.push(node{stx, sty, 0});
	while(!q.empty()) {
		node now = q.front(); q.pop();
		if(now.x == edx && now.y == edy) return now.step;
		for(int i = 0;i < 4; i++) {
			int nx = now.x + tx[i];
			int ny = now.y + ty[i];
			if(nx > n || nx < 1 || ny > m || ny < 1 || a[nx][ny] == '#' || vis[nx][ny]) continue;
			vis[nx][ny] = 1;
			q.push(node{nx, ny, now.step+1});
		}
	}
	return -1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		while(!q.empty()) q.pop();
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				vis[i][j] = 0;
				scanf(" %c", &a[i][j]);
				if(a[i][j] == 'S') stx = i, sty = j;
				if(a[i][j] == 'E') edx = i, edy = j;
			}
		}
		
		int ans = bfs();
		if(ans == -1) puts("oop!");
		else printf("%d\n", ans);
	}
}