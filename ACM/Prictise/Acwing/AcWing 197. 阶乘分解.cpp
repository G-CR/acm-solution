#include <bits/stdc++.h>
using namespace std;

const int N = 2e6;
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
map <int, int> num;

int main() {
	getprime();
	scanf("%d", &n);
	for(int i = 0; prime[i] <= n; i++) {
		long long now = prime[i];
		while(now <= n) {
			num[prime[i]] += n / now;
			now *= prime[i];
		}
	}
	for(auto i: num) {
		printf("%d %d\n", i.first, i.second);
	}
}