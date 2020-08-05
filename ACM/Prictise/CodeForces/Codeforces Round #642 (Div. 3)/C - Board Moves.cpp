#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		long long sum = 0, t = 1, num = 1;
		for(int i = 1;i <= n/2; i++) {
			sum += t*num*4+4*t; t++; num += 2;
		}
		printf("%lld\n", sum);
	}
}