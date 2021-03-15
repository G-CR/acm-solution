#include <bits/stdc++.h>
using namespace std;

int n, m;
double a[100005];

bool check(double mid) {
	int res = 0;
	for(int i = 1;i <= n; i++) {
		res += int(a[i]/mid);
		if(res >= m) return 1;
	}
	return 0;
}

int main() {
	scanf("%d %d", &n, &m);
	double ma = 0;
	for(int i = 1;i <= n; i++) {
		scanf("%lf", &a[i]);
		ma = max(ma, a[i]);
	}
	double l = 0, r = ma;
	while(fabs(l-r) > 0.001) {
		double mid = (l + r) / 2.0;
		if (check(mid)) l = mid;
		else r = mid;
	}
	
	printf("%.2lf\n", l);
}