#include <bits/stdc++.h>
using namespace std;

long long u, v;

int main() {
	scanf("%lld %lld", &u, &v);
	if(u > v || (v-u)%2) {
		puts("-1");
	}
	else if(u == v) {
		if(u == 0) puts("0");
		else {
			puts("1");
			printf("%lld\n", u);
		}
	}
	else {
		long long x = (v-u)/2;
		if((x&u) == 0) {
			puts("2");
			printf("%lld %lld\n", x, x+u);
		}
		else {
			puts("3");
			printf("%lld %lld %lld\n", x, x, u);
		}
	}
}