#include <bits/stdc++.h>
using namespace std;
const int M = 10000000;
int _, n, cas;
bool isprime[M+5];
int prime[700000], cnt;

void solve() {
	for(int i = 1;i <= M; i++) isprime[i] = 1;
	for(int i = 3;i <= M; i++) if(!(i%2)) isprime[i] = 0;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
	isprime[1] = 0;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) prime[++cnt] = i;
	}
}

int main() {
	solve();
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int ans = 0;
		for(int i = 1;n/2 >= prime[i] && i <= cnt; i++) {
			if(isprime[n-prime[i]]) {
//				printf("%d + %d = %d\n", prime[i], n-prime[i], n);
				ans++;
			} 
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
}