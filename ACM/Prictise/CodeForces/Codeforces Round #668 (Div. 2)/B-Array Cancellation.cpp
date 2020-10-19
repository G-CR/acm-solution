#include <bits/stdc++.h>
using namespace std;

int _, n;
long long a[100005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		long long sum = 0, ans = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%lld", &a[i]);
			sum += a[i];
			if(sum < 0) {
				ans += abs(sum);
				sum = 0;
			}
		}
		printf("%lld\n", ans);
	}
}