#include <bits/stdc++.h>
using namespace std;

struct node {
	int step;
	int floor, r, c;
};
int n;
char mp[105][105][105];
bool vis[105][105][105];
queue <node> q;

int bfs() {
	struct node t;
	t.floor = 1; t.r = 1; t.c = 1; t.step = 1;
	q.push(t);
	vis[1][1][1] = 1;
	while(!q.empty()) {
		t = q.front(); q.pop();
		
		if(t.floor == n && t.r == n && t.c == n) return t.step;
		struct node now;
		for(int k = -1;k <= 1; k++) {
			for(int i = -1;i <= 1; i++) {
				for(int j = -1;j <= 1; j++) {
					if(k != 0 && i != 0) continue;
					if(k != 0 && j != 0) continue;
					if(i != 0 && j != 0) continue;
					
					now.floor = t.floor+k;
					now.r = t.r+i;
					now.c = t.c+j;
					
					if(now.floor < 1 || now.floor > n || now.r < 1 || now.r > n || now.c < 1 || now.c > n) continue;
					if(vis[now.floor][now.r][now.c]) continue;
					if(mp[now.floor][now.r][now.c] == '*') continue;
					
					now.step = t.step+1;
					vis[now.floor][now.r][now.c] = 1;
					q.push(now);
				}
			}
		}
	}
	return -1;
}

int main() {
	scanf("%d", &n);
	for(int k = 1;k <= n; k++) {
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= n; j++) {
				scanf(" %c", &mp[k][i][j]);
			}
		}
	}
	
	printf("%d\n", bfs());
}