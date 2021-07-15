#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int isprime[N+10], prime[N+10];
int pn = 0;

void getprime() {
	memset(isprime, -1, sizeof(isprime));
	isprime[1] = 0;
	for(int i = 2;i < N;i++){
		if(isprime[i]) prime[pn++] = i;
		for(int j = 0;j < pn && 1ll*i*prime[j] < N;j++) {
			isprime[i*prime[j]] = 0;
			if(i % prime[j] == 0) break;
		}
	}
}

int n, a[100005];

int main() {
	getprime();
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		int now = i, num = 0;
		for(int j = 0; j < pn; j++) {
			if(now < prime[j]) break;
			while(now % prime[j] == 0) {
				num++;
				now /= prime[j];
			}
		}
		a[i] = num+1;
	}
	
	for(int i = 1; i <= n; i++) printf("%d ", a[i]);
}