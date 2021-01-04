#include <bits/stdc++.h>
using namespace std;

long long a, b, c;
long long num;

int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	long long ans = 0;
	num = min(a, b);
	a -= num; b -= num; ans += num;
	
	num = min(a, c);
	a -= num; c -= num; ans += num;
	
	ans +=  c / 2;
	
	printf("%lld\n", ans);
}