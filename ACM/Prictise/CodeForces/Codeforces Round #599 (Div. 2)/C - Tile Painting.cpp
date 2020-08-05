#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld", &n);
	long long t = -1;
	for(long long i = 2;i*i <= n; i++) {
		if(n % i == 0) {
			t = i; break;
		}
	}
	
	if(t == -1) printf("%lld\n", n);
	else {
		while(n % t == 0) {
			n /= t;
		}
		if(n == 1) printf("%lld\n", t);
		else puts("1");
	}
}

// 963201794869