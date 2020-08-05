#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int T;
double m, d;

int main() {
	scanf("%d", &T);
	for(int p = 1;p <= T; p++) {
		scanf("%lf %lf", &m, &d);
		printf("Case %d: ", p);
		double r = pow((m/d)*(3.0/4.0)/pi,1.0/3);
		printf("%.4lf\n", 4.0*pi*r*r);
	}
}