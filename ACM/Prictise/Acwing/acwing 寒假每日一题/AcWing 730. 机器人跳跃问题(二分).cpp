#include <bits/stdc++.h>
using namespace std;

int n, h[100005];

bool check(long long mid) {
	for(int i = 1;i <= n; i++) {
		int t = abs(mid - h[i]);
		if(mid >= h[i]) mid += t;
		else mid -= t;
		if(mid < 0) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &h[i]);
	}
	
	long long l = 0, r = 1e5, ans = 0;
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