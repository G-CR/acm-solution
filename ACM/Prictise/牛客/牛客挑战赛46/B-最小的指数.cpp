#include <bits/stdc++.h>
using namespace std;

const int N = 1e4;
int isprime[N+10];
long long prime[N+10];
int cnt;

void solve() {
	for(int i = 2;i <= N; i++) isprime[i] = 1;
	for(int i = 2;i <= N; i++) {
		if(isprime[i]) {
			prime[cnt++] = 1ll*i;
			for(int j = i*2; j <= N; j += i)
				isprime[j] = 0;
		}
	}
}

int _;
long long n;

int main() {
	solve();
	scanf("%d", &_);
	while(_--) {
		scanf("%lld", &n);
//		cout << "n = " << n << endl;
		if(n == 1) {puts("0"); continue;}
		int ans = 100;
		for(int i = 0;i < cnt; i++) {
			int num = 0;
			while(n % prime[i] == 0) {
				num++;
				n /= prime[i];
			}
			if(num) ans = min(ans, num);
		}
		if(n == 1) {
			printf("%d\n", ans);
		}
		else {
			long long sqr2 = (long long)sqrt(n);
			if(sqr2 * sqr2 == n) {
				long long sqr4 = (long long)sqrt(sqr2);
				if(sqr4 * sqr4 * sqr4 * sqr4 == n) ans = min(ans, 4);
				else if(sqr2 * sqr2 == n) ans = min(ans, 2);
			}
			else {
				long long l = 1e4, r = 1e6, mid;
				while(l <= r) {
					mid = (l+r) / 2;
					if(mid * mid * mid > n) {
						r = mid-1;
					}
					else if(mid * mid * mid < n) {
						l = mid+1;
					}
					else {
						break;
					}
				}
				if(mid*mid*mid == n) ans = min(ans, 3);
				else ans = 1;
			}
			printf("%d\n", ans);
		}
	}
}