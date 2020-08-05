#include <bits/stdc++.h>
using namespace std;

vector <int> g[1000006];
int val[1000006], times;
int l[1000006], r[1000006];
int n, m, k;
long long sum[1000006];

int lowbit(int x) {
	return x&-x;
}

void update(int pos, int num) {
	while(pos <= n) {
		sum[pos] += num;
		pos += lowbit(pos);
	}
}

long long getsum(int pos) {
	long long res = 0;
	while(pos) {
		res += sum[pos];
		pos -= lowbit(pos);
	}
	return res;
}

void dfs(int son, int father) {
	l[son] = ++times;
	update(times, val[son]);
	for(int i = 0;i < g[son].size(); i++) {
		int grandson = g[son][i];
		if(grandson != father) {
			dfs(grandson, son);
		}
	}
	r[son] = times;
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &val[i]);
	}
	int u, v;
	for(int i = 1;i < n; i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dfs(k, 0);
//	for(int i = 1;i <= n; i++) printf("%d ", l[i]); puts("");
	int choose, x, y;
	for(int i = 1;i <= m; i++) {
		scanf("%d", &choose);
		if(choose == 1) {
			scanf("%d %d", &x, &y);
			update(l[x], y);
		}
		else {
			scanf("%d", &x);
			printf("%lld\n", getsum(r[x])-getsum(l[x]-1));
		}
	}
}