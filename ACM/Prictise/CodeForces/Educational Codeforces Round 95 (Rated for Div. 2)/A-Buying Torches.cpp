#include <bits/stdc++.h>
using namespace std;

int _;
long long x, y, k;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %lld", &x, &y, &k);
		long long zeng = x-1;
		long long numc = k*y;
		long long tot = numc + k;
		printf("%lld\n", (tot-1+(zeng-1))/zeng + k);
	}
}