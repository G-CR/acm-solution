#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n, m;
ll w[200005], v[200005], s;
int l[200005], r[200005];
ll prenum[200005], presum[200005];

ll cal(ll f) {
	for(int i = 1;i <= n; i++) {
		if(w[i] >= f) {
			prenum[i] = prenum[i-1] + 1;
			presum[i] = presum[i-1] + v[i];
		}
		else {
			prenum[i] = prenum[i-1];
			presum[i] = presum[i-1];
		}
	}
	ll res = 0;
	for(int i = 1;i <= m; i++) {
		res += (prenum[r[i]]-prenum[l[i]-1]) * (presum[r[i]]-presum[l[i]-1]);
	}
	
	return res;
}

int main() {
	scanf("%d %d %lld", &n, &m, &s);
	for(int i = 1;i <= n; i++) {
		scanf("%lld %lld", &w[i], &v[i]);
	}
	for(int i = 1;i <= m; i++) {
		scanf("%d %d", &l[i], &r[i]);
	}
	
	ll l = 0, r = 1e18;
	while (l < r) {
		ll mid = (l + r + 1) >> 1;
		if (cal(mid) >= s) l = mid;
		else r = mid - 1;
	}
	
	printf("%lld\n", min(abs(cal(r) - s), abs(s - cal(r + 1))));
}