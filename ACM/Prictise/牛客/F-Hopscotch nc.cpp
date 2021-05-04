// https://ac.nowcoder.com/acm/contest/15329/F
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k;
ll a[55][55];
ll dp[2600][55][55];
vector <pair <ll, ll> > g[3000];

ll dfs(ll p, ll x, ll y) {
	if(dp[p][x][y] != -1) return dp[p][x][y];
	if(p == k+1) {
		return 0;
	}
	ll res = 1e18;
	for(ll i = 0; i < g[p].size(); i++) {
		ll nx = g[p][i].first, ny = g[p][i].second;
		res = min(res, dfs(p+1, nx, ny)+(abs(nx-x)+abs(ny-y)));
	}
	return dp[p][x][y] = res;
}

int main() {
	memset(dp, -1, sizeof(dp));
	scanf("%lld %lld", &n, &k);
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			scanf("%lld", &a[i][j]);
			g[a[i][j]].push_back({i, j});
		}
	}
	
	bool ok = 1;
	for(ll i = 1; i <= k; i++) {
		if(g[i].empty()) {
			ok = 0;
			break;
		}
	}
	
	if(!ok) puts("-1");
	else {
		if(n == 1) {
			return puts("0"), 0;
		}
		ll ans = 1e18;
		for(ll i = 0; i < g[1].size(); i++) {
			ll nx = g[1][i].first, ny = g[1][i].second;
//			prllf("nx = %d ny = %d\n", nx, ny);
			ll now = dfs(2, nx, ny);
//			prllf("now = %d\n", now);
			ans = min(ans, now);
		}
		printf("%lld\n", ans);
	}
}