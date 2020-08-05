#include <bits/stdc++.h>
using namespace std;

int n;
long long x, a[55];

long long gcd(long long a, long long b) {
	if(b == 0) return a;
	else return gcd(b, a%b);
}

long long lcm(long long a, long long b) {
	return a*b/gcd(a,b);
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	scanf("%lld", &x);
	
	long long res = 1;
	for(int i = 1;i <= n; i++) {
		if(x % a[i] == 0) {
			res = lcm(res, a[i]);
		}
	}
	
	if(res%x == 0) puts("Possible");
	else puts("Impossible");
}