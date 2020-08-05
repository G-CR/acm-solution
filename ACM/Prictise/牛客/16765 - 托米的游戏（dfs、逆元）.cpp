#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
vector <int> g[100005];
int n, dep[100005];

void dfs(int cnt, int fa, int deep) {
	dep[cnt] = deep;
	for(auto to: g[cnt]) {
		if(to == fa) continue;
		dfs(to, cnt, deep+1);
	}
}

int inv(int a,int b){  
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) res=1ll*res*a%mod;  
	return res;
}

int main() {
	scanf("%d", &n);
	int u, v;
	for(int i = 1;i <= n-1; i++) {
		scanf("%d %d", &u, &v);
		g[u].push_back(v); g[v].push_back(u);
	}
	dfs(1,1,1);
	int ans = 0;
	for(int i = 1;i <= n; i++) {
		ans = (ans+inv(dep[i], mod-2))%mod;
	}
	printf("%d\n", (ans+mod)%mod);
}