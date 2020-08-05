#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n;
ll a[105],anst,ans;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1;i <= n; i++) {
		anst = 0;
		for(int j = 1;j <= n; j++) {
			ll t = a[i];
			if(abs(a[j] - t)%2) anst++;
		}
		if(i == 1) {
			ans = anst;
			continue;
		}
		ans = min(ans,anst);
	}
	printf("%lld\n", ans);
}