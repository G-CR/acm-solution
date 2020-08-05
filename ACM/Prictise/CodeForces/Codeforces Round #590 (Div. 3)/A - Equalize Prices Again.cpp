#include <bits/stdc++.h>
using namespace std;

int q, n;
int a[105];

int main() {
	scanf("%d", &q);
	while(q--) {
		scanf("%d", &n);
		int sum = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		int ans = ceil(((float)sum/(float)n));
		printf("%d\n", ans);
	}
}