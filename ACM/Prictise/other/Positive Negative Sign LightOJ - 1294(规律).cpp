#include <bits/stdc++.h>
using namespace std;

int _;
long long n, m;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lld %lld", &n, &m);
		printf("Case %d: ", ++cas);
		long long cnt = n/(2*m);
		long long sum = m*m;
		printf("%lld\n", sum*cnt);
	}
}