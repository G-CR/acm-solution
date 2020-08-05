#include <bits/stdc++.h>
using namespace std;

int n, m, stax, stay, endx, endy;
char g[55][55];
int dirx[] = {1,-1,0,0};
int diry[] = {0,0,1,-1};
bool vis[55][55];
vector <pair <int, int> > vc;

struct node {
	int x, y, step;
	node(int a, int b, int c) {x=a;y=b;step=c;}
};
queue <node> q;


int main() {
	memset(vis, 0, sizeof(vis));
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf(" %c", &g[i][j]);
			if(g[i][j] == 'S') stax = i, stay = j;
			if(g[i][j] == 'E') endx = i, endy = j;
			if(g[i][j] == '*') vc.push_back(make_pair(i, j));
		}
	}
	
	int k = vc.size();
	for(int p = 0;p < k; p++) {
		int i = vc[p].first, j = vc[p].second;
//		cout << i << " " << j << endl;
		g[i-1][j-1] = '*'; g[i-1][j] = '*'; g[i-1][j+1] = '*';
		g[i][j-1] = '*';                    g[i][j+1] = '*'; 
		g[i+1][j-1] = '*'; g[i+1][j] = '*'; g[i+1][j+1] = '*';
	}
	
	if(g[endx][endy] == '*') puts("Impossible");
	else {
		int ans = -1;
		while(!q.empty()) q.pop();
		q.push(node(stax, stay, 0)); 
		vis[stax][stay] = 1;
		while(!q.empty()) {
			node t = q.front(); q.pop();
			if(endx == t.x && endy == t.y) {
				ans = t.step;
				break;
			}
			for(int i = 0;i < 4; i++) {
				int tx = t.x+dirx[i];
				int ty = t.y+diry[i];
				if(g[tx][ty] == '*' || vis[tx][ty] || tx > n || ty > m || tx < 1 || ty < 1) continue;
				vis[tx][ty] = 1;
				q.push(node(tx, ty, t.step+1));
			}
		}
		if(ans == -1) puts("Impossible");
		else printf("%d\n", ans);
	}
}