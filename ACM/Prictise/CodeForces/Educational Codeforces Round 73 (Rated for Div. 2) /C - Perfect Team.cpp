#include <bits/stdc++.h>
using namespace std;

long long q,c,m,x;

int main() {
	scanf("%lld", &q);
	while(q--) {
		scanf("%lld %lld %lld", &c, &m ,&x);
		if(c <= x || m <= x) {
			printf("%lld\n", min(c,m));
		}
		else {
			printf("%lld\n", min(min(c,m),(x+c+m)/3));
		}
	}
}