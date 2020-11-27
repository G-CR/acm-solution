#include <bits/stdc++.h>
using namespace std;

int n, a[500005];
int fa[500005];
int vis[500005];

int fin(int x) {
	if(fa[x] == x) return x;
	return fa[x] = fin(fa[x]);
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) fa[i] = i;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	
	for(int i = 1;i <= n; i++) {
		if(i > 1 && a[i] == 0) {
			int u = fin(i), v = fin(i-1);
			fa[u] = v;
		}
		else if(i < n && a[i] == 1) {
			int u = fin(i), v = fin(i+1);
			fa[u] = v;
		}
	}
	
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		int f = fin(i);
		if(!vis[f]) {
			ans++;
			vis[f] = 1;
		}
	}
	
	printf("%d\n", ans);
}