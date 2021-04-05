#include <bits/stdc++.h>
using namespace std;

long long n, k, q, x, y;

int main() {
	scanf("%lld %lld %lld", &n, &k, &q);
	int mi = 1, ma = n;
	while(q--) {
		scanf("%lld %lld", &x, &y);
		if(x > y) swap(x, y);
		int cha = min(abs(x-mi), abs(y-ma))+1;
		printf("%lld\n", k * cha);
	}
}