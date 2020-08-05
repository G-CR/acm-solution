#include <bits/stdc++.h>
using namespace std;

int k, n;
int a[1005];

bool cmp(int a, int b) {
	return a > b;
}

int main() {
	scanf("%d", &k);
	while(k--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n, cmp);
		int ans = 0;
		for(int i = 1;i <= n; i++) {
			ans = max(ans, min(a[i], i));
		}
		printf("%d\n", ans);
	}
}