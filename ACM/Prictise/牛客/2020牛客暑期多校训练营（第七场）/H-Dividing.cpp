#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9+7;
long long n, k;

long long cal(long long cnt) {
	long long sum = 0;
	for(long long i = 2,r; i <= k; i = r+1) {
		if(cnt/i == 0) break;
		r = min(cnt/(cnt/i), k);
		sum = (sum + ((r-i+1)%mod * (cnt/i)%mod)%mod) % mod;
	}
	return sum%mod;
}

int main() {
	scanf("%lld %lld", &n, &k);
	printf("%lld\n", ((cal(n)+cal(n-1))%mod+(k+n-1)%mod)%mod);
}