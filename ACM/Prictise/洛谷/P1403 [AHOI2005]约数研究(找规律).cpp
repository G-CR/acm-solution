#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	long long ans = 0;
	for(int i = 1;i <= n; i++) {
		ans += (n/i);
	}
	printf("%lld\n", ans);
}