#include <bits/stdc++.h>
using namespace std;

long long n, k;

long long cal(long long x) {
	long long num = x / k;
	long long res = (1+num) * num / 2;
	return res * k;
}

int main() {
	scanf("%lld %lld", &n, &k);
	long long ans = 0;
	for(int i = 1;i <= n; i++) {
		ans += cal(i);
	}
	
	printf("%lld\n", ans);
}