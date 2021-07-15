#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+7;
const int mod = 1e9+7;
vector <pair <int, ll> > g[N];
ll sum[N];

void dfs(int s, int fa) {
	for(auto i: g[s]) {
		int t = i.first;
		if(t == fa) continue;
		sum[t] = sum[s] ^ i.second;
		dfs(t, s);
	}
}

int main() {
	int n; scanf("%d", &n);
	for(int i = 1; i < n; i++) {
		int u, v; ll w; scanf("%d %d %lld", &u, &v, &w);
		g[u].push_back({v, w});
		g[v].push_back({u, w});
	}
	
	dfs(1, -1);
	ll ans = 0;
	for(int i = 0; i < 61; i++) {
		int num = 0;
		for(int j = 1; j <= n; j++) num += (sum[j] >> i) & 1;
		ans = (ans + ((1ll << i) % mod * num % mod * (n-num)) % mod) % mod;
	}
	
	printf("%lld\n", ans);
}