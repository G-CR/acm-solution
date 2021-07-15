#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-12;
double a, b;

double f(double x) { // 需要求的函数
	return sin(x) / x;
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
	scanf("%lf %lf", &a, &b);
	printf("%lf\n", solve(a, b));
}