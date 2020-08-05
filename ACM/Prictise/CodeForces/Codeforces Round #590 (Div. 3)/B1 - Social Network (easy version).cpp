#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, k;
ll a[200005],ans[200005];

void tiao(ll t) {
	for(int i = k;i >= 2; i--) {
		ans[i] = ans[i-1];
	}
	ans[1] = t;
}

int main() {
	scanf("%d %d", &n, &k);
	bool ok = 0;
	int j;
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		ok = 0;
		for(j = 1;j <= k; j++) {
			if(ans[j] == a[i]) {
				ok = 1;
				break;
			}
		}
		if(ok) continue;
		tiao(a[i]);
	}
	int t = 0;
	for(int i = 1;i <= k; i++) {
		if(ans[i]) t++;
	}
	printf("%d\n", t);
	for(int i = 1;i <= k; i++) {
		if(ans[i]) printf("%lld ", ans[i]);
	}
}