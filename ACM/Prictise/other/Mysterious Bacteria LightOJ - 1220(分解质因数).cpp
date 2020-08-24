#include <bits/stdc++.h>
using namespace std;

int _;
long long n;

const int M = 1000000;
bool isprime[M+5];
int prime[M+5], cnt, ans, cas;

int gcd(int a, int b) {return b==0?a:gcd(b,a%b);}

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
	for(int i = 1;i <= cnt && prime[i] <= x; i++) {
		int sum = 0;
		while(x%prime[i] == 0) {
			sum++;
			x /= prime[i];
		}
		ans = ans==0?sum:gcd(ans, sum);
	}
	if(x > 1) ans = 1;
}

int main() {
	solve();
	scanf("%d", &_);
	while(_--) {
		ans = 0;
		scanf("%lld", &n);
		getfac(abs(n));
		if(n < 0) while(ans%2==0) ans /= 2;
		printf("Case %d: %d\n", ++cas, ans);
	}
}