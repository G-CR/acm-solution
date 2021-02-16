#include <bits/stdc++.h>
using namespace std;

int n, m, num, k, x, y;
int a[103][103];
int tx[] = {0,0,-1,1};
int ty[] = {1,-1,0,0};
struct node {
	int x, y;
	int tim;
};
queue <node> q;

int main() {
	scanf("%d %d %d", &n, &m, &num);
	for(int i = 1;i <= num; i++) {
		scanf("%d %d", &x, &y);
		q.push({x, y, 0});
	}
	scanf("%d", &k);
	
	while (!q.empty()) {
		node t = q.front(); q.pop();
		if(t.tim > k) break;
		a[t.x][t.y] = 1;
		for(int i = 0;i < 4; i++) {
			int nowx = t.x + tx[i];
			int nowy = t.y + ty[i];
			if(nowx < 1 || nowx > n || nowy < 1 || nowy > m) continue;
			if(a[nowx][nowy]) continue;
			q.push({nowx, nowy, t.tim+1});
		}
	}
	
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			ans += a[i][j];
		}
	}
	
	printf("%d\n", ans);
	return 0;
}