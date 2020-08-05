#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500005];

int main() {
	scanf("%lld %lld", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	
	long long sum = 0;
	int ans = n;
	for(int i = 1;i <= n; i++) {
		if(sum + a[i] > m) {
			ans = i-1;
			break;
		}
		sum += a[i];
	}
	
	printf("%d\n", ans);
}