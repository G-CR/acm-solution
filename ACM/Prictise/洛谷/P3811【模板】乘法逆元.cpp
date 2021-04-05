#include <bits/stdc++.h>
using namespace std;

long long n, p;
long long inv[3000006];

int main() {
	scanf("%lld %lld", &n, &p);
	inv[1] = 1; puts("1");
	for(int i = 2; i <= n; i++) {
		inv[i] = 1ll * (p - p/i) * inv[p%i] % p;
		printf("%lld\n", inv[i]);
	}
}