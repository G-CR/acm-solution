#include <bits/stdc++.h>
using namespace std;

int _;
long long w, h, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %lld", &w, &h, &n);
		long long ans = 1;
		while(w%2==0) ans *= 2, w /= 2;
		while(h%2==0) ans *= 2, h /= 2;
		printf("%s\n", ans>=n?"YES":"NO");
	}
}