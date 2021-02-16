#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
const int N = 8e7;
int isprime[N+10], prime[N+10];
int pn = 0;
void getprime() {
	memset(isprime, -1, sizeof(isprime));
	for(int i = 2;i < N;i++){
		if(isprime[i]) prime[pn++] = i;
		for(int j = 0;j < pn && 1ll*i*prime[j] < N;j++) {
			isprime[i*prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}

int n;

int main() {
	getprime();
	scanf("%d", &n);
	if(n < 6) return puts("empty"), 0;
	
	long long ans = 1;
	
	for(int i = 1;i < pn; i++) {
		long long now = 1;
		while(now * prime[i] <= n / 2) now *= prime[i];
		ans = ans * now % mod;
	}
	long long now = 1;
	while(now * 2 <= n/3) now *= 2;
	ans = ans * now % mod;
	
	printf("%lld\n", ans);
}