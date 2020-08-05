#include <bits/stdc++.h>
using namespace std;

int n;
long long a[200005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	
	long long sum = a[n];
	for(int i = n-1;i >= 1; i--) {
		a[i] = min(a[i+1]-1, a[i]);
		sum += a[i];
		a[i] = max((long long)1, a[i]);
	}
	printf("%lld\n", sum);
}