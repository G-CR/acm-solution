#include <bits/stdc++.h>
using namespace std;

int _, n;
long long x[2002], y[2002];

struct node {
	int u, v;
	long long w;
}line[4000006];
int vis[2003][2003];
long long mp[2003][2003];

long long cal(int i, int j) {
	return (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]);
}

bool cmp(node a, node b) {
	return a.w > b.w;
}

void bfs(int pos, long long len) {
	for(int i = 1; i <= n; i++) {
		if(i == pos) continue;
		int fi = min(i, pos);
		int se = max(i, pos);
		if(len > mp[fi][se]) vis[fi][se] = 2;
	}
}


int main() {
	scanf("%d", &_);
	while(_--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld %lld", &x[i], &y[i]);
		}
		
		int cnt = 0;
		for(int i = 1; i <= n; i++) {
			for(int j = i+1; j <= n; j++) {
				mp[i][j] = cal(i, j);
				line[++cnt].u = i;
				line[cnt].v = j;
				line[cnt].w = mp[i][j];
			}
		}
		
		sort(line+1, line+1+cnt, cmp);
		
		for(int i = 1;i <= cnt; i++) {
			int u = line[i].u, v = line[i].v;
			if(vis[u][v]) continue;
			vis[u][v] = 1;
			bfs(u, mp[u][v]);
			bfs(v, mp[u][v]);
		}
		
		bool ok = 0;
		for(int i = 2;i <= n; i++) {
			if(vis[1][i] == 1) {
				ok = 1;
				break;
			}
		}
		
		if(ok) puts("YES");
		else puts("NO");
	}
}