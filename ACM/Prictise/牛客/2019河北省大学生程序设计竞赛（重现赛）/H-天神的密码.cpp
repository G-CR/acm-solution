#include <bits/stdc++.h>
using namespace std;

int _;
long long n, k;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &n, &k);
		if(k == 2) n = n*n;
		long long now;
		do {
			now = 0;
			long long t = n;
			while(n) {
				int a = n%10;
				now += a;
				n /= 10;
			}
			n = now;
		} while (now >= 10);
		printf("%lld\n", now);
	}
}