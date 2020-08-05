#include <bits/stdc++.h>
using namespace std;

int n, m;
int fa[200005], sum[200005];

int find(int x) {
	if(x != fa[x]) {
		int t = fa[x];
		fa[x] = find(fa[x]);
		sum[x] += sum[t];
	}
	return fa[x];
}

int main() {
	while(~scanf("%d %d", &n, &m)) {
		for(int i = 0;i <= n; i++) {
			fa[i] = i;
			sum[i] = 0;
		}
		int l, r, w, ans = 0;
		while(m--) {
			scanf("%d %d %d", &l, &r, &w); 
			l--;
			int fl = find(l);
			int fr = find(r);
			if(fl == fr) {
				if((sum[l]-sum[r]) != w) {
					ans++;
				} 
			}
			else {
				fa[fl] = fr;
				sum[fl] = -sum[l] + sum[r] + w;
			}
		}
		printf("%d\n", ans);
	}
}