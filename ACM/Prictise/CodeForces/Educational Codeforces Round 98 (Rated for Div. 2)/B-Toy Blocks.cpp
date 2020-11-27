#include <bits/stdc++.h>
using namespace std;

int _, n;
long long a[100005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		sort(a+1, a+1+n);
		
		long long ans = 0;
		for(int i = 2;i < n; i++) {
			if(a[1] >= a[n]-a[i]) a[1] -= a[n]-a[i];
			else {
				ans += (a[n]-a[i]-a[1]);
				a[1] = 0;
			}
		}
		a[1] %= n-1;
		if(a[1]) {
			ans += (n-1)-a[1];
		}
		
		printf("%lld\n", ans);
	}
}