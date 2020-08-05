#include <bits/stdc++.h>
using namespace std;

long long t, x, y, a, b;

int main() {
	scanf("%lld", &t);
	while(t--) {
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if((y-x)%(a+b) == 0 ) {
			printf("%lld\n", (y-x)/(a+b));
		}
		else puts("-1");
	}
}