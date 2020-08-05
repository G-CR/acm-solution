#include <bits/stdc++.h>
using namespace std;

int n, u, v, cnt;
int fa[100005], num[100005];
map <int, int> mp;

int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

int main() {
	while(~scanf("%d", &n)) {
		cnt = 0;
		mp.clear();
		for(int i = 1;i <= 1e5; i++) fa[i] = i, num[i] = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d %d", &u, &v);
			if(!mp[u]) mp[u] = ++cnt;
			if(!mp[v]) mp[v] = ++cnt;
			int fu = find(mp[u]), fv = find(mp[v]);
			if(fu != fv) fa[fu] = fv;
		}
		
		for(int i = 1;i <= 1e5; i++) num[find(mp[i])]++;
//		for(int i = 1;i <= 1e5; i++) printf("i = %d %d\n",i, find(mp[i]));
		int ans = 1;
		for(int i = 1;i <= 1e5; i++) {
			ans = max(ans, num[i]);
		}
		
		printf("%d\n", ans);
	}
}