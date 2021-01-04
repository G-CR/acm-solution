#include <bits/stdc++.h>
using namespace std;

const int M = 1000;
bool isprime[M+5];
long long dp[1003];
int n;

void solve() {
	for(int i = 2;i <= M; i++) isprime[i] = 1;
	for(int i = 2;i <= M; i++) {
		if(isprime[i]) {
			for(int j = i*2; j<= M; j += i)
				isprime[j] = 0;
		}
	}
}

int main() {
	solve();
	dp[0] = 1;
	scanf("%d", &n);
	for(int i = 2;i <= n; i++) {
		if(!isprime[i]) continue;
		for(int j = 0;j <= n; j++) {
			if(dp[j] && i+j <= n) {
				dp[i+j] += dp[j];
			}
		}
	}
	printf("%lld\n", dp[n]);
}