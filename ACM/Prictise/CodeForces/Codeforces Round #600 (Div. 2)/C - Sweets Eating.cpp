#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[200005];
long long sum[200005];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	sort(a+1, a+1+n);
	
	for(int i = 1;i <= n; i++) {
		sum[i] = sum[i-1]+a[i];
		if(i > m) {
			sum[i] = sum[i]-sum[i-m-1]+sum[i-m];
		}
		printf("%lld ", sum[i]);
	}
}