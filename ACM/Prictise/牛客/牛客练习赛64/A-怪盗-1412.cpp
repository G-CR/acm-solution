#include <bits/stdc++.h>
using namespace std;

int _;
long long n, m, k;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %lld", &n, &m, &k);
		long long t = n >> 1;
		t = n - t; n -= t;
		printf("%lld\n", t*n*m*k);
	}
}