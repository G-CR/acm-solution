#include <bits/stdc++.h>
using namespace std;

int _;
long long a, b;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &a, &b);
		long long ans = 0, r = 1e18;
		while(r-ans>=2) {
			long long mid = (ans+r)/2;
			if(a >= mid && b >= mid && (a+b)/3 >= mid) ans = mid;
			else r = mid;
		}
		printf("%lld\n", ans);
	}
}