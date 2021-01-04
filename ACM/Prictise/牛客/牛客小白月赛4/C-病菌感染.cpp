#include <bits/stdc++.h>
using namespace std;

int n, m;
struct Point {
	int x, y;
} p[1003];

bool vis[1003][1003];
int num[1003][1003];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};
queue <Point> q;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &p[i].x, &p[i].y);
		vis[p[i].x][p[i].y] = 1;
		num[p[i].x][p[i].y] = 2;
		q.push(p[i]);
	}
	
	while(!q.empty()) {
		Point now = q.front(); q.pop();
		for(int i = 0;i < 4; i++) {
			int tx = now.x+dx[i], ty = now.y+dy[i];
			if(tx < 1 || tx > n || ty < 1 || ty > n) continue;
			if(vis[tx][ty]) continue;
			num[tx][ty]++;
			if(num[tx][ty] >= 2) {
				vis[tx][ty] = 1;
				q.push(Point{tx, ty});
			}
		}
	}
	
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= n; j++) {
			if(num[i][j] < 2) ans++;
		}
	}
	
	puts(ans==n*n?"YES":"NO");
}