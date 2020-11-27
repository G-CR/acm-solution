#include <bits/stdc++.h>
using namespace std;

int n;
long long a[102];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	for(int i = 3;i <= n; i++) {
		if(a[i-2]+a[i-1] > a[i]) {
			printf("%lld %lld %lld\n", a[i-2], a[i-1], a[i]);
			return 0;
		}
	}
	puts("No solution");
}