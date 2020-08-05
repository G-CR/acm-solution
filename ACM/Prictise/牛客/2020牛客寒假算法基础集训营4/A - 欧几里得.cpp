#include <bits/stdc++.h>
using namespace std;

int n, t;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		long long a = 2, b = 1;
		if(n == 0) {
			puts("1");
			continue;
		}
		for(int i = 2;i <= n; i++) {
			long long t = b;
			b = a;
			a = a+t;
		}
		printf("%lld\n", a+b);
	}
	
}