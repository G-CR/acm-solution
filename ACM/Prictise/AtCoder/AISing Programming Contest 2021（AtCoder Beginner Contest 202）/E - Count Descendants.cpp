#include <bits/stdc++.h>
using namespace std;
const int N = 2e5+7;
int n, dep[N], in[N], out[N];
vector <int> g[N], res[N];

int now = 0;
void dfs(int p) {
	in[p] = now++;
	res[dep[p]].push_back(in[p]);
	for(int to: g[p]) {
		dep[to] = dep[p] + 1;
		dfs(to);
	}
	out[p] = now++;
}

int main() {
	scanf("%d", &n);
	for(int i = 2; i <= n; i++) {
		int p; scanf("%d", &p);
		g[p].push_back(i);
	}
	dfs(1);
	
	int q; scanf("%d", &q); while(q--) {
		int u, len; scanf("%d %d", &u, &len);
		auto x = lower_bound(res[len].begin(), res[len].end(), out[u]);
		auto y = lower_bound(res[len].begin(), res[len].end(), in[u]);
		
		printf("%d\n", (int)(x - y));
	}
}