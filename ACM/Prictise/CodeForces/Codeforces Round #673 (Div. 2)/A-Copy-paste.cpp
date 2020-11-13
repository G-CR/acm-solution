#include <bits/stdc++.h>
using namespace std;

int _, n, k;
int a[1004];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		int now = 1e9, pos;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			if(now > a[i]) {
				now = a[i];
				pos = i;
			}
		}
		
		long long ans = 0;
		for(int i = 1;i <= n; i++) {
			if(pos == i) continue;
			ans += (k-a[i])/now;
		}
		
		printf("%lld\n", ans);
	}
}