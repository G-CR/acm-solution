#include <bits/stdc++.h>
using namespace std;

int _, n, cas;
map <int, int> mp;
bool huan[200005];
int fa[200005], siz[200005];

int find(int x) {
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	scanf("%d", &_);
	while(_--) {
		int now = 0;
		mp.clear();
		memset(huan, 0, sizeof(huan));
		for(int i = 1;i <= 200000; i++) fa[i] = i, siz[i] = 1;
		
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			int u, v;
			scanf("%d %d", &u, &v);
			if(!mp[u]) mp[u] = ++now;
			if(!mp[v]) mp[v] = ++now;
			int fu = find(mp[u]);
			int fv = find(mp[v]);
			if(fu == fv) {
				huan[fu] = 1;
			}
			else {
				fa[fu] = fv;
				siz[fv] += siz[fu];
				if(huan[fu]) huan[fv] = 1;
			}
		}
		
		long long ans = 0;
		for(int i = 1;i <= now; i++) {
			int fi = find(i);
			if(fi != i)continue;
			ans += siz[fi];
			if(!huan[fi]) ans--;
		}
		
		printf("Case #%d: %lld\n",++cas, ans);
	}
}