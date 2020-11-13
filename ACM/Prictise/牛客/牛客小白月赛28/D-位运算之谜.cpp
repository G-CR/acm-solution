#include <bits/stdc++.h>
using namespace std;

int _;
long long x, y;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &x, &y);
		long long rem = x-2*y;
		if(rem < 0 || (rem & y) > 0) puts("-1");
		else printf("%lld\n", rem);
	}
}