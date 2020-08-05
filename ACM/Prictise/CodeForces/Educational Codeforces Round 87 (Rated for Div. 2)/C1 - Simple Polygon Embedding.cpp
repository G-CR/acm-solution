#include <bits/stdc++.h>
using namespace std;
const double pi = acos(-1);
int _, n;

int main() {
	scanf("%d", &_);
	double sqr2 = sqrt(2.0);
	while(_--) {
		scanf("%d", &n);
		n *= 2;
		double r = tan((n-2)*pi/2/n)/2;
		printf("%.9lf\n", r*2);
	}
}