#include <bits/stdc++.h>
using namespace std;

int _, n, a[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		int l = 1, r = 2;
		long long ans = 0;
		while(r <= n) {
			if(a[r]-a[l] <= 2) {
				long long len = r-l+1;
				if(len >= 3) {
					ans = ans + (len-1) * (len-2) / 2;
				}
				r++;
			}
			else {
				l++;
			}
		}
		
		printf("%lld\n", ans);
	}
}