#include <bits/stdc++.h>
using namespace std;

int n, u, v, cnt[200005];
vector <int> g[200005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i < n; i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 0;j < g[i].size(); j++) {
			cnt[i] += g[g[i][j]].size()-1;
		}
	}
	
	for(int i = 1;i <= n; i++) {
		printf("%d\n", cnt[i]);
	}
}