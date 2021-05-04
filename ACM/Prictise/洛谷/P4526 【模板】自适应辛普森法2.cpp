#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
double a;

double f(double x) {
	return pow(x, a/x-x);
}

double simpson(double l, double r) {
	return (r-l) * (f(l) + 4*f((l+r)/2) + f(r)) / 6;
}

double solve(double l, double r) {
	double s = simpson(l, r);
	double mid = (l + r) / 2;
	double left = simpson(l, mid), right = simpson(mid, r);
	if(fabs(left + right - s) < eps) return left + right;
	return solve(l, mid) + solve(mid, r);
}

int main() {
	scanf("%lf", &a);
	if(a < 0) puts("orz");
	else printf("%.5f\n", solve(eps, 15));
}