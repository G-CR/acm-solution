#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld", &n);
	long long ans = n/4;
	long long res = n-ans*4;
	ans *= 2;
	if(res == 3) ans += 1;
	else ans += res;
	
	printf("%lld\n", ans);
}