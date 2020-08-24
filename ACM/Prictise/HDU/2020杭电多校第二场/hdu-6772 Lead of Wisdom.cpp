#include <bits/stdc++.h>
using namespace std;
const int N = 55;
int _, n, k, cnt;
struct node {
	int t, a, b, c, d;
} wq;
long long resa, resb, resc, resd, dmg;
vector <node> v[N];
map <int, int> mp;

void dfs(int cas) {
	if(cas == cnt+1) {
		dmg = max(dmg, resa*resb*resc*resd);
		return;
	}
	for(auto i: v[cas]) {
		resa += i.a; resb += i.b; resc += i.c; resd += i.d;
		dfs(cas+1);
		resa -= i.a; resb -= i.b; resc -= i.c; resd -= i.d;
	}
}

int main() {
	scanf("%d", &_);
	while(_--) {
		cnt=0;
		mp.clear();
		resa = resb = resc = resd = 100;
		dmg = resa*resb*resc*resd;
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= k; i++) v[i].clear();
		for(int i = 1;i <= n; i++) {
			scanf("%d %d %d %d %d", &wq.t, &wq.a, &wq.b, &wq.c, &wq.d);
			if(!mp[wq.t]) mp[wq.t] = ++cnt;
			v[mp[wq.t]].push_back(wq);
		}
		dfs(1);
		printf("%lld\n", dmg);
	}
}