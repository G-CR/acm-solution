#include <bits/stdc++.h>
using namespace std;

long long a, b, p;

int main() {
	scanf("%lld %lld %lld", &a, &b, &p);
	long long res = 0;
	
	while(b) {
		if(b & 1) {
			res = (res + a) % p;
		}
		a = a * 2 % p;
		b >>= 1;
	}
	
	printf("%lld\n", res);
}