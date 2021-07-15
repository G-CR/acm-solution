#include <bits/stdc++.h>
using namespace std;

int g[10][10];

void init() {
	g[1][2] = g[1][6] = 1;
	g[2][1] = g[2][7] = g[2][3] = 1;
	g[6][1] = g[6][7] = g[6][5] = 1;
	g[7][2] = g[7][3] = g[7][5] = g[7][6] = 1;
	g[3][7] = g[3][4] = g[3][2] = 1;
	g[5][4] = g[5][7] = g[5][6] = 1;
	g[4][3] = g[4][5] = 1;
}

int fa[10];
int fin(int x) {
	if(x == fa[x]) return x;
	return fa[x] = fin(fa[x]);
}

vector <int> a;

int dfs(int p) {
	if(p == 8) {
		if(a.empty()) return 0;
		for(int i: a) fa[i] = i;
		
		for(int i = 0; i < a.size(); i++) {
			for(int j = i+1; j < a.size(); j++) {
				int u = a[i], v = a[j];
				if(!g[u][v]) continue;
				int fu = fin(u), fv = fin(v);
				if(fu == fv) continue;
				fa[fu] = fv;
			}
		}
		
		int father = fin(a[0]);
		for(int i = 1; i < a.size(); i++) {
			if(fin(a[i]) != father) return 0;
		}
		for(int i: a) printf("%d ", i); puts("");
		return 1;
	}
	
	int res = 0;
	res += dfs(p+1);
	
	a.push_back(p);
	res += dfs(p+1);
	a.pop_back();
	
	return res;
}

int main() {
	init();
	printf("%d\n", dfs(1));
}