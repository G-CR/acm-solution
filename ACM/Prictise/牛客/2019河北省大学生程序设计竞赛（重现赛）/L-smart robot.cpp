#include <bits/stdc++.h>
using namespace std;

int n;
int a[55][55];
bool visdig[100005];
int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct node {
	int x, y;
	int dig;
	node(int a, int b, int digi) {
		x = a;
		y = b;
		dig = digi;
	}
};

void bfs(int sx, int sy) {
	if(a[sx][sy] == 0) return;
	queue <node> q; while(!q.empty()) q.pop();
	q.push(node(sx, sy, a[sx][sy]));
	visdig[a[sx][sy]] = 1;
	
	while(!q.empty()) {
		node now = q.front(); q.pop();
//		printf("now = %d\n", now.dig);
		for(int i = 0;i < 4; i++) {
			int tx = now.x+dx[i], ty = now.y+dy[i];
			if(tx < 1 || tx > n || ty < 1 || ty > n)
				continue;
			int news = now.dig*10+a[tx][ty];
			if(news < 100000) {
				q.push(node(tx, ty, news));
				visdig[news] = 1;
			} 
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= n; j++) {
			bfs(i, j);
		}
	}
	
	for(int i = 1;i <= 100000; i++) {
		if(!visdig[i]) {
			printf("%d\n", i);
			break;
		}
	}
}