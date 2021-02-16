#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[1000006], pre[1000006];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	for(int i = 1;i <= n; i++) {
		pre[i] = pre[i-1] + a[i];
	}
	while(m--) {
		int l, r;
		scanf("%d %d", &l, &r);
		printf("%lld\n", pre[r]-pre[l-1]);
	}
	
}