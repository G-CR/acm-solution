#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-8;

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point {
	double x, y;
	Point(){}
	Point(double _x,double _y) {
		x = _x; y = _y;
	}
	void input() {
		scanf("%lf %lf", &x, &y);
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x,y - b.y);
	}
	double operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
};

double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

struct Line {
	Point s, e;
	Line(){}
	Line(Point _s, Point _e) {
		s = _s; e = _e;
	}
};

Point NearestPointToLineSeg(Point P,Line L) {
	Point result;
	double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
	if(t >= 0 && t <= 1) {
		result.x = L.s.x + (L.e.x - L.s.x)*t;
		result.y = L.s.y + (L.e.y - L.s.y)*t;
	}
	else {
		if(dist(P,L.s) < dist(P,L.e))
			result = L.s;
		else result = L.e;
	}
	return result;
}

int n;
Point p[1003];

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) p[i].input();
	double ans = 1e18;
	for(int i = 0; i < n; i++) {
		Line l (p[(i-1+n)%n], p[(i+1)%n]);
		Point now = NearestPointToLineSeg(p[i], l);
		ans = min(ans, 0.5 * dist(p[i], now));
	}
	
	printf("%.10f\n", ans);
}