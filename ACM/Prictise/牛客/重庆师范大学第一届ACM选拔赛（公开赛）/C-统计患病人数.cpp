#include <bits/stdc++.h>
using namespace std;

int x, n, m;
int fa[100005];

int find(int x) {
	if(x == fa[x]) return x;
	else return fa[x] = find(fa[x]);
}

int main() {
	scanf("%d %d %d", &x, &n, &m);
	for(int i = 0;i <= x; i++) fa[i] = i;
	int cnt, fat, t;
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &cnt, &fat);
		int u = find(fat);
		for(int j = 2;j <= cnt; j++) {
			scanf("%d", &t);
			int v = find(t);
			fa[v] = u;
		}
	}
	for(int i = 0;i < x; i++) int k = find(i);
	int meile = find(n);
//	for(int i = 0;i < x; i++) printf("fa[%d] = %d\n", i, fa[i]);
//	printf("meile = %d\n", meile);
	vector <int> ans;
	for(int i = 0;i < x; i++) {
		if(find(i) == meile) ans.push_back(i);
	}
	printf("%d ", (int)ans.size());
	for(int i: ans) printf("%d ", i); puts("");
}