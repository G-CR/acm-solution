#include <bits/stdc++.h>
using namespace std;

int _, n, a[100005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int maxx = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			maxx = max(maxx, a[i]);
		}
		printf("%d\n", maxx);
	}
}