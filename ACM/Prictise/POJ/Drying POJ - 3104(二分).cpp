#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
long long k, a[100005], ma = -1;

bool check(long long mid) {
	long long tim = 0;
	if(ma <= mid) return 1;
	for(int i = 1;i <= n; i++) {
		long long t = a[i];
		t = max(1ll*0, t - mid);
		tim += (t+k-1)/k;
	}
	if(tim > mid) return 0;
	return 1;
}

int main() {
	while(~scanf("%d", &n)) {
		ma = -1;
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
			ma = max(ma, a[i]);
		}
		
		scanf("%lld", &k); k--;
		if(!k) {printf("%lld\n", ma); continue;}
		
		long long l = 1, r = ma, ans = 0;
		while(l <= r) {
			long long mid = (l + r) / 2;
			if(check(mid)) {
				ans = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		printf("%lld\n", ans);
	}
}