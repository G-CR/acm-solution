#include <bits/stdc++.h>
using namespace std;

int x, y, n, q, a[100005];

int main() {
	scanf("%d %d", &n, &q);
	int res = 0;
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
		res ^= a[i];
	}
	while(q--) {
		scanf("%d %d", &x, &y);
		res ^= a[x];
		a[x] = y;
		res ^= a[x];
		if(res == 0) puts("Li");
		else puts("Kan");
	}
}