#include <bits/stdc++.h>
using namespace std;

int n, m;
unsigned long long a[1000006];

bool check(unsigned long long mid) {
	int res = 0;
	unsigned long long now = 0;
	
	for(int i = 1;i <= n; i++) {
		if(a[i] > mid) return 0;
		if(now + a[i] > mid) {
			res++;
			now = a[i];
		}
		else now += a[i];
	}
	
	if(now) res++;
	return res <= m;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%llu", &a[i]);
	}
	unsigned long long l = 0, r = 1e19, ans;
	while(l <= r) {
		unsigned long long mid = (l + r) >> 1;
		if(check(mid)) {
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	
	printf("%llu\n", ans);
}