#include <bits/stdc++.h>
using namespace std;

int _, n, k;
long long a[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= n*k; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a+1, a+1+n*k);
		
		long long ans = 0;
		if(n == 1) {
			for(int i = 1;i <= n*k; i++) {
				ans += a[i];
			}
		}
		else if(n == 2) {
			for(int i = 1;i <= n*k; i += 2) {
				ans += a[i];
			}
		}
		else {
			int mid = (n+1)/2;
			for(int i = (mid-1)*k+1; i <= n*k; i += n-(mid-1)) {
//				printf("%lld ", a[i]);
				ans += a[i];
			} //puts("");
		}
		
		printf("%lld\n", ans);
	}
}