#include <bits/stdc++.h>
using namespace std;

int n, k, q;
long long a[2000006], pre[2000006];

int main() {
	scanf("%d %d %d", &n, &k, &q);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	pre[1] = 1;
	for(int i = 2;i <= n; i++) {
		pre[i] = pre[i-1] + (a[i] != a[i-1]);
	}
	
//	for(int i = 1;i <= n; i++) printf("%lld ", pre[i]); puts("");
	
	int l, r;
	while(q--) {
		scanf("%d %d", &l, &r);
		long long ans = pre[r] - pre[l-1];
		if(pre[l-1] == pre[l]) ans++;
//		printf("ans = %lld\n", ans);
		printf("%s\n", ans>=k?"Yes":"No");
	}
}