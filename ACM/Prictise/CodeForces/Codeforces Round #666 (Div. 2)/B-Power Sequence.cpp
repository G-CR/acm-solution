#include <bits/stdc++.h>
using namespace std;

int n;
long long a[100005];

int main() {
	scanf("%d", &n);
	long long sum = 0;
	for(int i = 1;i <= n; i++) {
		scanf("%lld", &a[i]);
		sum += a[i];
	}
	sum -= n;
//	printf("sum = %lld\n", sum);
	bool ok = 1;
	sort(a+1, a+1+n);
	long long ans = 1e18;
	for(int i = 2;i <= 100000000; i++) {
		long long now = 1, res = 0;
		for(int j = 1;j <= n; j++) {
			res += abs(now-a[j]);
			if(res > sum) {
				ok = 0;
				break;
			}
			now *= i;
		}
//		if(i == 31623) {
//			printf("res = %lld\n", res);
//		}
		if(!ok) {
			ans = min(ans, sum);
			break;
		} 
		ans = min(ans, res);
	}
	printf("%lld\n", ans);
}