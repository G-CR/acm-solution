#include <bits/stdc++.h>
using namespace std;

int _;
double v1, v2, v3, a1, a2;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lf %lf %lf %lf %lf", &v1, &v2, &v3, &a1, &a2);
		double x1 = (v1*v1)/(2*a1);
		double x2 = (v2*v2)/(2*a2);
		double d = x1+x2; 
		double t = max(v1/a1, v2/a2);
		double fin = v3*t;
		printf("Case %d: %.8lf %.8lf\n", ++cas, d, fin);
	}
}