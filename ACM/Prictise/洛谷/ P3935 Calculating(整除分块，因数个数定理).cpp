#include <bits/stdc++.h>
using namespace std;
const int mod = 998244353;
long long l, r;

long long cal(long long n) {
	long long i, j, res = 0;
	for(i = 1;i <= n; i = j+1) {
		j = n/(n/i);
		res = (res + ((j-i+1)%mod)*((n/i)%mod))%mod;
	}
	return res;
}

int main() {
	scanf("%lld %lld", &l, &r);
	printf("%lld\n", (cal(r)-cal(l-1)+mod)%mod);
}