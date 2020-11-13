#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
int _;
double l[3];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lf %lf %lf", &l[0], &l[1], &l[2]);
		sort(l, l+3);
		printf("%.12lf\n", PI*(l[1]*l[1] + (l[2]-l[1])*(l[2]-l[1])));
	}
}