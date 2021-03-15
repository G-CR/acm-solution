#include <bits/stdc++.h>
using namespace std;

int n, m;
struct node {
	int u, v;
	long long c;
} re[100005];
int col[20004];
vector <int> g[20004];

bool cmp(node a, node b) {
	return a.c > b.c;
}

bool dfs(int pos, int c) {
	col[pos] = c;
	for(int i = 0;i < g[pos].size(); i++) {
		int now = g[pos][i];
		if(!col[now]) {
			bool ok = dfs(now, -c);
			if(!ok) return 0;
		}
		else if(col[now] == c) return 0;
	}
	return 1;
}

bool isbg(int mid) {
	for(int i = 1;i <= n; i++) g[i].clear(), col[i] = 0;
	for(int i = 1;i <= mid; i++) {
		int u = re[i].u, v = re[i].v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	for(int i = 1;i <= n; i++) {
		if(!col[i]) {
			bool ok = dfs(i, 1);
			if(!ok) return 0;
		}
	}
	return 1;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= m; i++) {
		scanf("%d %d %lld", &re[i].u, &re[i].v, &re[i].c);
	}
	sort(re+1, re+1+m, cmp);
	int l = 1, r = m, ans;
	while(l <= r) {
		int mid = (l + r) >> 1;
		if(isbg(mid)) {
			ans = mid;
			l = mid+1;
		}
		else r = mid-1;
	}
	
	printf("%lld\n", re[ans+1].c);
}