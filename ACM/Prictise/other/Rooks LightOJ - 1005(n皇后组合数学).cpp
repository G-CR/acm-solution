#include <bits/stdc++.h>
using namespace std;

int _, cas;
long long n, k;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &n, &k);
		printf("Case %d: ", ++cas);
		if(k > n) {
			puts("0");
			continue;
		}
		long long ans = 1, t = n;
		for(int i = 1;i <= k; i++) {
			ans *= t--;
		}
		
		long long sum = 1;
		for(long long i = n, j = 1;j <= k; i--, j++) {
			sum *= i;
			sum /= j;
		}
		printf("%lld\n", ans*sum);
	}
}