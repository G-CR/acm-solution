#include <bits/stdc++.h>
using namespace std;

int _;
long long n, k;

int findmin(long long x) {
	int k = 9;
	while(x) {
		int t = x%10;
		k = min(k, t);
		x /= 10;
	}
	return k;
}

int findmax(long long x) {
	int k = 0;
	while(x) {
		int t = x%10;
		k = max(k, t);
		x /= 10;
	}
	return k;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &n, &k); k--;
		while(k--) {
			int a = findmin(n);
			int b = findmax(n);
			if(a == 0) break;
			n += (long long)a*b;
		}
		printf("%lld\n", n);
	}
}