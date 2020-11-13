#include <bits/stdc++.h>
using namespace std;

int _, k, n;
long long a[200005];

bool cmp(long long a, long long b) {return a > b;}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		
		sort(a+1, a+1+n, cmp);
		
		long long ans = 0;
		for(int i = 1;i <= k+1; i++) {
			ans += a[i];
		}
		
		printf("%lld\n", ans);
	}
}