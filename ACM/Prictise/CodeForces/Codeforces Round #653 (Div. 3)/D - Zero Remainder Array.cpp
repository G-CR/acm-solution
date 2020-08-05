#include <bits/stdc++.h>
using namespace std;

int _;
long long n, k, x;
map<long long, int> mp;

int main() {
	scanf("%d", &_);
	while(_--) {
		mp.clear();
		scanf("%lld %lld", &n, &k);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &x);
			if(x%k == 0) continue;
			mp[x%k]++;
		}
		
		long long ans = 0;
		for(auto i = mp.begin(); i != mp.end(); i++) {
			ans = max(ans, (i->second-1)*k+(k-i->first));
		}
		if(ans == 0) puts("0");
		else printf("%lld\n", ans+1);
	}
}