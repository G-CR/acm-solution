#include <bits/stdc++.h>
using namespace std;

int n;
double a[100005];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lf", &a[i]);
	}
	
	sort(a+1, a+1+n);
	double pos;
	if(n % 2) pos = a[(n+1)/2];
	else pos = (a[n/2] + a[n/2+1]) / 2;
	double ans = 0;
	for(int i = 1;i <= n; i++) {
		ans += fabs(pos-a[i]);
	}
	
	printf("%lld\n", (long long)ans);
}