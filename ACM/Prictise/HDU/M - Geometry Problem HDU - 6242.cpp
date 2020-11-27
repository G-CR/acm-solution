#include <iostream>
#include <cmath>
#include <time.h>
using namespace std;
const double eps = 1e-8;

double sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point { // 表示点
	double x, y;
	Point(){}
	Point(double _x,double _y) {
		x = _x; y = _y;
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x,y - b.y);
	}
	double operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
};

//两点距离
double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

Point solve(Point a, Point b, Point c) { // 三点共圆圆心公式
	double X, Y;
	double fm1=2 * (a.y - c.y) * (a.x - b.x) - 2 * (a.y - b.y) * (a.x - c.x);
	double fm2=2 * (a.y - b.y) * (a.x - c.x) - 2 * (a.y - c.y) * (a.x - b.x);
	if (fm1 == 0 || fm2 == 0) {
		X = Y = 1e18;
		return Point(X, Y);
	}
	double fz1=a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y;
	double fz2=a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y;
	X = (fz1 * (a.y - c.y) - fz2 * (a.y - b.y)) / fm1;
	Y = (fz1 * (a.x - c.x) - fz2 * (a.x - b.x)) / fm2;
	
	return Point(X, Y);
}

int _, n;
Point p[100005];

bool check(Point cen, double r) {
	int res = 0;
	for(int i = 1;i <= n; i++) {
		if(sgn(dist(cen, p[i]) - r) == 0) {
			res++;
			if(res >= (n+1)/2) break;
		} 
	}
	return res >= (n + 1) / 2;
}

int main() {
	srand(time(NULL));
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		if(n == 1 || n == 2) {
			printf("%lf %lf 1.0\n", p[1].x+1, p[1].y);
			continue;
		}
		if(n == 3 || n == 4) {
			printf("%lf %lf %lf\n", (p[1].x+p[2].x)/2, (p[1].y+p[2].y)/2, dist(p[1], p[2])/2);
			continue;
		}
		
		Point ansp; double ansr;
		while (1) {
			int one = rand() % n + 1;
			int two = rand() % n + 1;
			int three = rand() % n + 1;
			if(one == two || two == three || one == three) continue;
			Point cen = solve(p[one], p[two], p[three]);
			if(cen.x == 1e18) continue;
			double r = dist(cen, p[one]);
			
			if(check(cen, r)) {
				ansp = cen; ansr = r;
				break;
			}
		}
		
		if(sgn(ansp.x-0.0) == 0) ansp.x = 0;
		if(sgn(ansp.y-0.0) == 0) ansp.y = 0;
		printf("%lf %lf %lf\n", ansp.x, ansp.y, ansr);
	}
}