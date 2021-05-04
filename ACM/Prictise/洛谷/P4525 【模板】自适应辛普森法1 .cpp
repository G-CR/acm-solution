#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-12;
double a, b, c, d, l, r;

double f(double x) {
	return (c*x+d) / (a*x+b);
}

double simpson(double l, double r) {
	return (r - l) * (f(l) + 4 * f((l+r)/2) + f(r)) / 6;
}

double solve(double l, double r) {
	double s = simpson(l, r);
	double mid = (l + r) / 2;
	double left = simpson(l, mid), right = simpson(mid, r);
	if(fabs(left + right - s) < eps) return left + right;
	return solve(l, mid) + solve(mid, r);
}

int main() {
	scanf("%lf %lf %lf %lf %lf %lf", &a, &b, &c, &d, &l, &r);
	printf("%.6f\n", solve(l, r));
}