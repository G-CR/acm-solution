#include <bits/stdc++.h>
using namespace std;

int fa[100005], sum[100005];
int n, m, q;

int find(int x) {
	if(fa[x] != x) {
		int t = fa[x];
		fa[x] = find(fa[x]);
		sum[x] += sum[t];
	}
	return fa[x];
}

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for(int i = 0;i <= n; i++) {
		sum[i] = 0;
		fa[i] = i;
	}
	int l, r, s;
	while(m--) {
		scanf("%d %d %d", &l, &r, &s);
		int fl = find(l);
		int fr = find(r);
		if(fl != fr) {
			fa[fl] = fr;
			sum[fl] = -sum[l] + sum[r] + s;
		}
	}
	
	while(q--) {
		scanf("%d %d", &l, &r);
		int fl = find(l);
		int fr = find(r);
		if(fl == fr) {
			printf("%d\n", sum[l]-sum[r]);
		}
		else puts("-1");
	}
}