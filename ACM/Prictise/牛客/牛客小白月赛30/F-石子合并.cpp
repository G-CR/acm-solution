#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005];

int main() {
	scanf("%d", &n);
	long long ma = -1;
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		ma = max(ma, a[i]);
	}
	
	bool ok = 0;
	long long ans = 0;
	for(int i = 1;i <= n; i++) {
		if(a[i] == ma && !ok) {
			ok = 1;
			continue;
		}
		ans += (a[i]+ma);
	}
	
	printf("%lld\n", ans);
}