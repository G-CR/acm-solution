#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005], b[200005], c[200005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &b[i]);
		c[i] = a[i] - b[i];
	}
	sort(c+1,c+1+n);
	long long ans = 0;
	for(int i = 1;i <= n; i++) {
		int cnt = upper_bound(c+1+i, c+1+n, -c[i])-c;
		ans += n-cnt+1;
	}
	printf("%lld\n", ans);
}