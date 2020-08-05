#include <bits/stdc++.h>
using namespace std;

int _;
long long a, b;

const int M = 1000000;
bool isprime[M+5];
int prime[M+5], cnt;

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

long long getfac(long long x) {
	long long ans=1;
	for(int i = 1;i <= cnt && prime[i] <= x; i++) {
		long long sum = 0;
		while(x%prime[i] == 0) {
			sum++;
			x /= prime[i];
		}
		ans *= (sum+1);
	}
	if(x>1) ans *= 2;
	return ans;
}

int main() {
	solve();
	int cas = 0;
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &a, &b);
		printf("Case %d: ", ++cas);
		if(a < b*b) {puts("0"); continue;}
		long long ans = getfac(a);
		ans /= 2;
		for(int i = 1;i < b; i++) {
			if(a%i == 0) ans--;
		}
		printf("%lld\n", ans);
	}
}