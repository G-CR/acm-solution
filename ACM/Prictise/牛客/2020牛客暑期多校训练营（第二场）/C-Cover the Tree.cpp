#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> g[200005], leap;

void dfs(int pos, int fa) {
	if(g[pos].size() == 1) {leap.push_back(pos); return;}
	for(int i = 0;i < g[pos].size(); i++) {
		if(g[pos][i] == fa) continue;
		dfs(g[pos][i], pos);
	}
}

int main() {
	scanf("%d", &n);
	int u, v, head = 0;
	for(int i = 1;i < n; i++) {
		scanf("%d %d", &u, &v);
		if(!head) head = u;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for(int i = 1;i <= n; i++) {
		if(g[i].size() > 1) {head = i; break;}
	}
	
	dfs(head, -1);
	int mid = ((int)leap.size()+1)/2;
	printf("%d\n", mid);
	
	for(int i = 0;i < mid; i++) {
		if(i+mid >= (int)leap.size()) printf("%d %d\n", leap[i], leap[mid]);
		else printf("%d %d\n", leap[i], leap[i+mid]);
	}
}

/*
5
1 2
2 3
3 4
3 5
*/