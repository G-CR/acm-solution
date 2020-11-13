#include <bits/stdc++.h>
using namespace std;

long long a, b, c, d;

long long gcd(long long a, long long b) {
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main() {
	while(~scanf("%lld %lld %lld %lld", &a, &b, &c, &d)) {
		long long l = max(a, c);
		long long r = min(b, d);
		if(l > r) {puts("0/1"); continue;}
		long long num = r-l+1;
		long long fenzi = num;
		long long fenmu = (d-c+1)*(b-a+1);
		long long t = gcd(fenzi, fenmu);
		printf("%lld/%lld\n", fenzi/t, fenmu/t);
	}
}