#include <bits/stdc++.h>
using namespace std;

int _;
long long n, m, k;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %lld", &n, &m, &k);
		long long y = k / n;
		long long x = k % n;
		if(x) y++;
		if(x == 0) x = n;
		printf("%lld\n", (x-1)*m+y);
	}
}