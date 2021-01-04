#include <bits/stdc++.h>
using namespace std;

const long long mod = 1e9+7;
long long a, b, m, n, f[100005];

long long phi(long long n) { // 求单个值的欧拉函数
	long long ans = n ;
	for(int i = 2 ; i*i<=n ; i++ ) {
		if(!(n%i)){
			ans = ans/i*(i-1) ;
			while(n%i == 0 ){
				n/=i ;
			}
		}
	}
	if(n>1) ans = ans/n*(n-1);
	return ans;
}

long long qpow(long long x, long long n) { 
	long long res = 1; 
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res; 
}

int main() {
	scanf("%lld %lld %lld %lld", &a, &b, &m, &n);
	f[1] = 1; f[2] = 1;
	long long mo = phi(mod);
	for(int i = 3;i <= n; i++) {
		f[i] = (a*f[i-1] + b*f[i-2])%mo;
	}
	printf("%lld\n", qpow(m, f[n]));
}