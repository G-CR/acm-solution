#include <bits/stdc++.h>
using namespace std;

long long l, r;
int main() {
	scanf("%lld %lld", &l, &r); l--;
	long long ans1 = r;
	while(r % 4 != 0 && r > 0) {
		r--;
		ans1 ^= r;
	}
	
	
	long long ans2 = l;
	while(l % 4 != 0 && l > 0) {
		l--;
		ans2 ^= l;
	}
	
	printf("%lld\n", ans1^ans2);
}