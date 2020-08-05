#include <bits/stdc++.h>
using namespace std;

int n, stai, staj, endi, endj;
int dirx[] = {0, 1, 0, -1};
int diry[] = {1, 0, -1, 0};
bool vis[105][105][5];
char g[105][105];
struct node {
	int x, y;
	int pre, cnt;
	node(int i, int j, int p, int c) {x=i;y=j;pre=p;cnt=c;}
	bool operator < (const node& a) const{
		return cnt > a.cnt;
	}
};
priority_queue <node> q;

int bfs() {
	q.push(node(stai, staj, 4, 0));
	while(!q.empty()) {
		node t = q.top(); q.pop();
		if(vis[t.x][t.y][t.pre]) continue;
		vis[t.x][t.y][t.pre] = 1;
		if(t.x == endi && t.y == endj) return t.cnt;
		for(int i = 0;i < 4; i++) {
			int tx = t.x+dirx[i], ty = t.y+diry[i], k; 
			if(tx<1||tx>n||ty<1||ty>n||g[tx][ty]=='x') continue;
			if(t.pre == i || t.pre == 4) k = 0;
			else k = 1;
			q.push(node(tx, ty, i, t.cnt+k));
		}
	}
	return -1;
}


int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= n; j++) {
			scanf(" %c", &g[i][j]);
			if(g[i][j] == 'A') stai = i, staj = j;
			if(g[i][j] == 'B') endi = i, endj = j;
		}
	}
	
	printf("%d\n", bfs());
}

/*
4
x x A .
x . . .
. . x .
B . . .
*/