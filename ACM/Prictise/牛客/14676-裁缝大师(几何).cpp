#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const double eps = 1e-6;
int _;
double x, y, r, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lf %lf %lf %lf", &x, &y, &r, &n);
		for(int i = n; i >= 1; i--) {
			double cosa = cos(((double)i/(double)n)*2*PI);
			double sina = sin(((double)i/(double)n)*2*PI);
			double ans1 = x+r*cosa, ans2 = y+r*sina;
			if(fabs(ans1-0.0) < eps) ans1 = 0.00;
			if(fabs(ans2-0.0) < eps) ans2 = 0.00;
			printf("%.2lf %.2lf\n", ans1, ans2);
		}
	}
}