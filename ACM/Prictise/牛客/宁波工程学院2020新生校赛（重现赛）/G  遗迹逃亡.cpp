#include <bits/stdc++.h>
using namespace std;

char g[505][505];
int n, m, stax, stay;
int dirx[] = {0,0,-1,1};
int diry[] = {-1,1,0,0};
bool vis[505][505];
queue <pair<int, int> > q;

int main() {
	memset(vis, 0, sizeof(vis));
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) for(int j = 1;j <= m; j++) {
		scanf(" %c", &g[i][j]);
		if(g[i][j] == 's') {stax = i; stay = j;}
	}
	
	bool ok = 0;
	while(!q.empty()) q.pop();
	q.push(make_pair(stax, stay)); vis[stax][stay] = 1;
	while(!q.empty()) {
		pair<int, int> t = q.front(); q.pop();
		if(g[t.first][t.second] == 'g') {ok = 1; break;}
		for(int i = 0;i < 4; i++) {
			int tx = t.first+dirx[i];
			int ty = t.second+diry[i];
			if(vis[tx][ty]||tx<1||tx>n||ty<1||ty>m||g[tx][ty]=='#') continue;
			vis[tx][ty] = 1;
			q.push(make_pair(tx, ty));
		}
	}
	
	if(ok) puts("Yes");
	else puts("No");
}