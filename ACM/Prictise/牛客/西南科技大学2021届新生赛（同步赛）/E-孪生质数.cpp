#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int isprime[N+10], prime[N+10];
int pn = 0;

void getprime() {
	memset(isprime, -1, sizeof(isprime));
	isprime[1] = 0; isprime[0] = 0;
	for(int i = 2;i < N;i++){
		if(isprime[i]) prime[pn++] = i;
		for(int j = 0;j < pn && 1ll*i*prime[j] < N;j++) {
			isprime[i*prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}

const long long mod = 1e9+7;
long long qpow(long long x, long long n) { 
	long long res = 1;
	for (; n; n >>= 1, x = x * x % mod) 
		if (n & 1) res = res * x % mod; 
	return res;
}

int _, n;
long long pre[N+10];

int main() {
	getprime();
	for(int i = 2; i <= N; i++) {
		if(isprime[i] && isprime[i-2]) pre[i] = pre[i-1] + 1;
		else pre[i] = pre[i-1];
	}
	
	scanf("%d", &_);
	while(_--) {
		long long n;
		scanf("%lld", &n);
		printf("%lld\n", (2ll*pre[n]*qpow(n*(n-1)%mod, mod-2)) % mod);
	}
}