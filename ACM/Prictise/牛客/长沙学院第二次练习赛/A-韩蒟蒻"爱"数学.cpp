#include <bits/stdc++.h>
using namespace std;

int _;
long long a, b, c;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld %lld", &a, &b, &c);
		if((b*c)%a || a == 0) {
			puts("-1");
			continue;
		}
		printf("%lld\n", b*c/a);
	}
}