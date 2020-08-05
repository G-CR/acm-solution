#include <bits/stdc++.h>
using namespace std;

int n, k;
long long a[100005];

int main() {
	scanf("%d %d", &n, &k);
	long long sum = 0;
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a+1, a+1+n);
	int cnt = 0;
	for(int i = 1;i <= k; i++) {
		sum += (a[n-cnt]-a[i]);
		cnt++;
	}
	printf("%lld\n", sum);
}