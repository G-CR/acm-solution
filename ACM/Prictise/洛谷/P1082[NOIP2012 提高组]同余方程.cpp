#include <bits/stdc++.h>
using namespace std;

long long a, b;

long long exgcd(long long a, long long b, long long &x, long long &y) {
	if(!b) {
		x = 1; y = 0;
		return a;
	}
	long long gcd = exgcd(b, a%b, y, x);
	y -= a/b*x;
	return gcd;
}

int main() {
	scanf("%lld %lld", &a, &b);
	long long x, y;
	exgcd(a, b, x, y);
	while(x < 0) x += b;
	printf("%lld\n", x);
}