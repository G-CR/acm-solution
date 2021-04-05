#include <bits/stdc++.h>
using namespace std;

const long long mod = 998244353;
long long pre[1000006];
int _, n;

int main() {
	int cnt = 1;
	for(int i = 1; i <= 1000000; i++) {
		pre[i] = (pre[i-1] + 1ll * i * cnt) % mod;
		cnt += 2;
	}
	
	scanf("%d", &_);
	while(_--) {
		long long ans = 0;
		scanf("%d", &n);
		printf("%lld\n", pre[n]);
	}
}