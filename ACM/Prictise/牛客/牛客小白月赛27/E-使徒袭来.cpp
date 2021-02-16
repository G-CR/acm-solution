#include <bits/stdc++.h>
using namespace std;

double n;

int main() {
	scanf("%lf", &n);
	double ans = pow(n, 1.0/3.0);
	printf("%.3lf\n", ans*3);
}