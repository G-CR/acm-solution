#include <bits/stdc++.h>
using namespace std;

int n;
long long a[1000006], s[1000006], avg;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		avg += a[i];
	}
	avg /= n;
	
	for(int i = 2;i <= n; i++) {
		s[i] = s[i-1] + a[i] - avg;
	}
	sort(s+1, s+1+n);
	
	long long mid = s[(n>>1)+1], ans = 0;
	
	for(int i = 1;i <= n; i++) {
		ans += abs(mid-s[i]);
	}
	
	printf("%lld\n", ans);
}