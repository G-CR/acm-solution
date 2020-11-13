#include <bits/stdc++.h>
using namespace std;

int _, n;
const int M = 10000;
bool isprime[M+5];
vector <int> prime;

void solve() {
	for(int i = 2;i <= M; i++) isprime[i] = 1;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			prime.push_back(i);
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
}

int main() {
	solve();
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int now = 0;
		for(int i: prime) {
			if(i >= n && !isprime[i-n+1]) {
				now = i-n+1;
			}
		}
		
		int should = n;
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= n; j++) {
				if(j == should) printf("%d ", now), should--;
				else printf("1 ");
			}
			puts("");
		}	
	}
}