#include <bits/stdc++.h>
using namespace std;

int _;
double l, w;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%lf %lf", &l, &w);
		double pos = (4*(l+w) - sqrt(16*(l+w)*(l+w)-4*12*l*w))/24;
		printf("Case %d: %lf\n", ++cas, (l-2*pos)*(w-2*pos)*pos);
	}
}