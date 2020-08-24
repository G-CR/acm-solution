#include <bits/stdc++.h>
using namespace std;

int _, n;
long long a[50004];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
		}
		if(a[1] + a[2] <= a[n]) {
			printf("1 2 %d\n", n);
		}
		else puts("-1");
	}
}