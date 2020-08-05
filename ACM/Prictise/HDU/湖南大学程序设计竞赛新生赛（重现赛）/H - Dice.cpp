#include <bits/stdc++.h>
using namespace std;

int t, n;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		double ans = 0, k = 0.5;
		while(n--) {
			ans += k;
			k /= 2.0;
		}
		printf("%.4lf\n", ans);
	}
}