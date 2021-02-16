#include <bits/stdc++.h>
using namespace std;

int _;
int d;

const int M = 100000;
bool isprime[M+5];
int prime[M+5];

void solve() {
	for(int i = 2;i <= M; i++) isprime[i] = 1;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
	
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			prime[++prime[0]] = i;
		}
	}
}

int main() {
	solve();
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &d);
		long long a, b;
		for(int i = 1;i <= prime[0]; i++) {
			if(prime[i]-1 >= d) {
				a = prime[i];
				for(int j = i+1;j <= prime[0]; j++) {
					if(prime[j]-a >= d) {
						b = prime[j];
						break;
					}
				}
				break;
			}
		}
		
		printf("%lld\n", a*b);
		
	}
}