#include <bits/stdc++.h>
using namespace std;

int _;
long long x, y, a, b;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %lld %lld", &x, &y, &a, &b);
		if(x < y) swap(x, y);
		long long sum = 0;
		if(2*a <= b) {
			sum += (x+y)*a;
		}
		else if(2*a > b) {
			sum += y*b;
			sum += (x-y)*a;
		}
		printf("%lld\n", sum);
	}
}