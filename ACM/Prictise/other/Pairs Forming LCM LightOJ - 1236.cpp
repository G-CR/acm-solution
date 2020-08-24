#include <bits/stdc++.h>
using namespace std;

int _, cas;
long long n;

const int M = 10000000;
bool isprime[M+5];
int prime[700000], cnt;

vector <int> num;

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

void getfac(long long x) {
	num.clear();
	for(int i = 1;i <= cnt && prime[i] <= x; i++) {
		long long sum = 0;
		while(x%prime[i] == 0) {
			sum++;
			x /= prime[i];
		}
		if(sum) num.push_back(sum);
	}
	if(x > 1) num.push_back(1);
}

int main() {
	solve();
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &n);
		getfac(n);
		long long ans = 1;
		for(int i: num) {
			ans *= 2*i+1;
		}
		printf("Case %d: %lld\n", ++cas, (ans+1)/2);
	}
}
