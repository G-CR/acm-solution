#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;
int isprime[N+10], prime[N+10];
int pn = 0;

void getprime() {
	memset(isprime, -1, sizeof(isprime));
	isprime[1] = 0;
	for(int i = 2; i < N; i++) {
		if(isprime[i]) prime[pn++] = i;
		for(int j = 0; j < pn && 1ll*i*prime[j] < N; j++) {
			isprime[i*prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}

int n;
int num[N+10];

int main() {
	getprime();
	scanf("%d", &n);
	if(n <= 2) puts("1");
	else puts("2");
	for(int i = 2; i <= n+1; i++) {
		if(isprime[i]) {
			printf("1 ");
		}
		else printf("2 ");
	}
	puts("");
}