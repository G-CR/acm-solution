#include <bits/stdc++.h>
using namespace std;

int _, n;
long long a[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		long long ans = 0, now = 1e18, hi = 0;
		for(int i = 1;i <= n; i++) {
			if(a[i] < a[i-1]) {
				hi = max(hi, a[i-1]);
				now = min(now, a[i]);
			} 
			else if(now != 1e18) {
				ans += hi-now;
				now = 1e18;
				hi = 0;
			}
//			printf("ans = %lld now = %lld\n",ans,  now);
		}
		if(now != 1e18) ans += hi-now;
		
		printf("%lld\n", ans);
	}
}