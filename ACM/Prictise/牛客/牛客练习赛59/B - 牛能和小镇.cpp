#include <bits/stdc++.h>
using namespace std;

long long x[100005], y[100005], len[100005];
int n;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lld %lld", &x[i], &y[i]);
		len[i] = (x[i]*x[i]*y[i]) + (y[i]*y[i]*(y[i]-2*x[i]));
	}
	sort(len+1, len+1+n);
	long long ans = 0;
	for(int i = 1;i < n; i++) {
		ans += len[i+1]-len[i];
	}
	
	printf("%lld\n", ans);
}