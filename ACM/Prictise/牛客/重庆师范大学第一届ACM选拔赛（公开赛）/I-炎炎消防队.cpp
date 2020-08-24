#include <bits/stdc++.h>
using namespace std;

int _;
double y;

double getdig(double x) {
	return 7*pow(x, 7) + 6*pow(x, 6) + 2*pow(x, 3) + 8*pow(x, 2) - y*x;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lf", &y);
		double ans = 100000000;
		for(double i = 0;i <= 100; i += 0.0001) {
			ans = min(ans, getdig(i));
		}
		printf("%lf\n", ans);
	}
}