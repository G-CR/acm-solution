#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+5;
vector <int> G[N];
ll p[N], h[N], uh[N], hp[N], _p[N], n, m, _;
bool flag;

bool check(ll P,ll H) {
	ll x,y;
	x = (P + H)/2;
	y = x - H;
	if(x+y == P && x >= 0 && y >= 0) return true;
	else return false;
}

void dfs(int u, int fa) {
	for(auto v: G[u]){
		if(v == fa) continue;
		dfs(v,u);
		p[u] += p[v];
	}
	hp[u] = (p[u] + h[u]) / 2;
	uh[u] = hp[u]-h[u];
	if(hp[u]+uh[u] != p[u] || uh[u] < 0 || hp[u] < 0) flag=0;
}

void dfs1(int u,int fa) {
	ll tmp=0;
	for(auto v: G[u]){
		if(v == fa) continue;
		dfs1(v, u);
		tmp += uh[v];
	}
	ll t=0;
	if(uh[u]<=_p[u]) t=0;
	else t=uh[u]-_p[u];
	// cout<<tmp<<" "<<t<<endl;
	if(tmp<t) flag=0;
}

int main() {
	flag = 1;
	scanf("%lld", &_);
	while(_--){
		scanf("%lld %lld", &n, &m);
		for(int i = 1;i <= n; i++) G[i].clear();

		for(int i = 1;i <= n; i++) {
			scanf("%lld", &p[i]);
			_p[i] = p[i]; 
		} 
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &h[i]);
		}
		
		for(int i = 1;i < n; i++){
			ll u, v;
			scanf("%lld %lld", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}

		flag = 1;
		dfs(1,0); dfs1(1,0);
		
		if(flag) puts("YES");
		else puts("NO");
	}
}