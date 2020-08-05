#include <bits/stdc++.h>
using namespace std;

int q, n, p[200005], a[200005], x[200005];

void dfs(int pos, int num, int k, int cnt) {
	x[cnt] = pos;
	if(pos == k) {
		for(int i = 1;i <= cnt; i++) a[x[i]] = num;
		return; 
	}
	dfs(p[pos], num+1, k, cnt+1);
}

int main() {
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &p[i]);
			a[i] = 0;
		}
		for(int i = 1;i <= n; i++) {
			if(a[i]) continue;
			x[1] = i;
			dfs(p[i], 1, i, 2);
		}
		for(int i = 1;i <= n; i++) printf("%d ", a[i]);
		puts("");
	}
}