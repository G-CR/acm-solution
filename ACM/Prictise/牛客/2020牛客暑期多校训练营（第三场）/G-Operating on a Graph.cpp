#include <bits/stdc++.h>
using namespace std;
const int N = 8e5+7;
int _, n, m, q;
vector <int> g[N], t;
int fa[N];
int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		for(int i = 0;i < n; i++) fa[i] = i, g[i].clear();
		for(int i = 1;i <= m; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			g[u].push_back(v);
			g[v].push_back(u);
		}
		scanf("%d", &q);
		while(q--) {
			int x;
			scanf("%d", &x);
			if(find(x) != x) continue;
			t = g[x]; g[x].clear();
			for(int i: t) {
				int ot = find(i);
				if(ot != x) {
					fa[ot] = x;
					if(g[x].size() < g[ot].size()) swap(g[x], g[ot]);
					for(int j: g[ot]) g[x].push_back(j);
				}
				
			}
		}
		for(int i = 0;i < n; i++) printf("%d ", find(i)); puts("");
	}
}