#include <bits/stdc++.h>
using namespace std;

int T;
double r;

int main() {
	scanf("%d", &T);
	for(int p = 1;p <= T; p++) {
		scanf("%lf", &r);
		printf("Case %d: ", p);
		printf("%.4lf\n", 1.0/4*r*r);
	}
}