#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;

double sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Cir {
	double x, y, r;
	double vx, vy;
} p1, p2;

double dist(double timi) {
	double p1x = p1.x + timi * p1.vx;
	double p1y = p1.y + timi * p1.vy;
	double p2x = p2.x + timi * p2.vx;
	double p2y = p2.y + timi * p2.vy;
	return sqrt((p1x-p2x)*(p1x-p2x)+(p1y-p2y)*(p1y-p2y)) - p1.r - p2.r;
}

int _;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lf %lf %lf %lf %lf", &p1.x, &p1.y, &p1.r, &p1.vx, &p1.vy);
		scanf("%lf %lf %lf %lf %lf", &p2.x, &p2.y, &p2.r, &p2.vx, &p2.vy);
		double l = 0, r = 1e9, res;
		
		while(sgn(l-r) != 0) {
			double tri = (r - l) / 3.0;
			double mid1 = l + tri, mid2 = r - tri;
			double res1 = dist(mid1);
			double res2 = dist(mid2);
			
			if(res1 <= res2) r = mid2;
			else l = mid1;
			res = (l + r) / 2;
		}
		
		if(dist(res) >= 1e-6) {
			printf("%.10lf\n", dist(res));
		}
		else {
			l = 0;
			while(sgn(l-r) != 0) {
				double mid = (l + r) / 2.0;
				if(dist(mid) > 0) l = mid;
				else r = mid;
			}
			
			printf("%.10lf\n", l);
		}
	}
}