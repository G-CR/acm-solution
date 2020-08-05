#include <bits/stdc++.h>
using namespace std;

int n;
vector <int> g[100005], ji, ou;
bool vis[100005];

void dfs(int pos, int jo) {
	vis[pos] = 1;
	if(jo == 1) ou.push_back(pos);
	else ji.push_back(pos);
	for(auto i:g[pos]) {
		if(vis[i]) continue;
		dfs(i, -jo);
	}
}

int main() {
	scanf("%d", &n);
	int u, v;
	for(int i = 1;i <= n-1; i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	dfs(1, -1);
	long long a = ji.size(), b = ou.size();
	printf("%lld\n", a*(a-1)/2+b*(b-1)/2);
}