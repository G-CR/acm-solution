#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
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
	while(~scanf("%d", &n) && n) {
		for(int i = 1; i < pn; i++) {
			if(isprime[n-prime[i]] && n-prime[i] != 2) {
				printf("%d = %d + %d\n", n, prime[i], n-prime[i]);
				break;
			}
		}
	}
}