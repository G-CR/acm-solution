#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
int _;
struct Circle {
	double x, y;
	double r;
} cir[2];

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

double dist(Circle a, Circle b) {
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

int rela(Circle a, Circle b) {
	double d = dist(a, b);
	if(sgn(d-a.r-b.r) > 0) return 5;
	if(sgn(d-a.r-b.r) == 0) return 4;
	double l = fabs(a.r - b.r);
	if(sgn(d-a.r-b.r) < 0 && sgn(d-l) > 0) return 3;
	if(sgn(d-l) == 0) return 2;
	if(sgn(d-l) < 0) return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lf %lf %lf %lf %lf %lf", &cir[0].x, &cir[0].y, &cir[0].r, &cir[1].x, &cir[1].y, &cir[1].r);
		int res = rela(cir[0], cir[1]);
//		cout << res << endl;
		if(res == 2 || res == 3 || res == 4) puts("YES");
		else puts("NO");
	}
}