#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005], b[100005];

bool check(long long k) {
	long long lun = k / n, ge = k % n;
	for(int i = 1;i <= n; i++) {
		b[i] = a[i] + lun;
		if(ge) b[i]++, ge--;
	}
	sort(b+1, b+1+n);
	long long mid = n%2?b[(n+1)/2]:(b[n/2]+b[n/2+1])/2;
	long long res = 0;
	for(int i = 1;i <= n; i++) {
		res += abs(b[i]-mid);
	}
	return res <= k;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	long long l = 0, r = 1e18, ans = 0;
	while(l <= r) {
		long long mid = (l + r) >> 1;
//		printf("l = %d r = %d mid = %d\n", l, r, mid);
		if(check(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}
	printf("%lld\n", ans);
}