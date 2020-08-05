#include <bits/stdc++.h>
using namespace std;

int _;
double minx, maxx, n, m;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lf %lf", &n, &m);
		double sum1 = 0, sum2 = 0, t;
		for(int i = 1;i <= n-1; i++) {
			scanf("%lf", &t);
			sum1 += t;
		}
		for(int i = 1;i <= m; i++) {
			scanf("%lf", &t);
			sum2 += t;
		}
		maxx = (sum1*n/(n-1))-sum1;
		minx = (sum2*(m+1)/m)-sum2;
		printf("%d %d\n", (int)floor(minx+1), (int)ceil(maxx-1));
	}
}