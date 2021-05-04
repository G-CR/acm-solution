#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005], ma[200005], pre[200005];

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		pre[i] = pre[i-1] + a[i];
		ma[i] = max(ma[i-1], pre[i]);
	}
	
	long long ans = 0, now = 0;
	for(int i = 1; i <= n; i++) {
		ans = max(ans, now + ma[i]);
		now += pre[i];
	}
	
	printf("%lld\n", ans);
}