#include <bits/stdc++.h>
using namespace std;

int n, x;

int main() {
	int ans = 0;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &x); x = abs(x);
		ans = __gcd(ans, x);
	}
	printf("%d\n", ans);
}