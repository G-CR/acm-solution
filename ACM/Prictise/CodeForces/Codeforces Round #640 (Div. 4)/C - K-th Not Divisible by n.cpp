#include <bits/stdc++.h>
using namespace std;

long long n, k;
int _;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &n, &k);
		long long l = 1, r = 1e18, ans;
		while(l <= r) {
			long long mid = (l+r)>>1;
			if(mid-mid/n>=k) {
				ans = mid;
				r = mid-1;
			}
			else l = mid+1;
		}
		printf("%lld\n", ans);
	}
}