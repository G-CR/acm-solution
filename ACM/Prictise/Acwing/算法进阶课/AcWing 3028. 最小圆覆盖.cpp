#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

const int N = 100010;
const double eps = 1e-12;
const double PI = acos(-1);

int sgn(double x) {
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
	Point operator + (const Point& b) const {
		return {x + b.x, y + b.y};
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x, y - b.y);
	}
	Point operator * (const double &b) const {
		return Point(x * b, y * b);
	}
	Point operator / (const double &b) const {
		return Point(x / b, y / b);
	}
	
	double operator * (const Point &b) const {
		return x*b.y - y*b.x;
	}
	bool operator < (Point b) const {
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0: x < b.x;
	}
	bool operator == (Point b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	Point rotate(Point p,double angle){ // 以p为圆心逆时针旋转angle
		Point v = (*this) - p;
		double c = cos(angle), s = sin(angle);
		return Point(p.x + v.x*c - v.y*s,p.y + v.x*s + v.y*c);
	}
};

struct Line { // 表示线段
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
};

struct circle {
	Point p;
	double r;
};

double get_dist(Point a, Point b) {
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

Point get_line_intersection(Point p, Point v, Point q, Point w) {
	Point u = p - q;
	double t = w * u / (v * w);
	return p + v * t;
}

Line get_line(Point a, Point b) {
	return Line((a + b) / 2, Point(b-a).rotate(Point(0,0), PI/2)); 
}

circle get_circle(Point a, Point b, Point c)
{
	auto u = get_line(a, b), v = get_line(a, c);
	auto p = get_line_intersection(u.s, u.e, v.s, v.e);
	return {p, get_dist(p, a)};
}

int n;
Point p[N];

circle solve() {
	random_shuffle(p, p + n);
	circle c({p[0], 0});
	for (int i = 1; i < n; i ++ ) {
		if (sgn(c.r-get_dist(c.p, p[i])) < 0) {
			c = {p[i], 0};
			
			for (int j = 0; j < i; j ++ ) {
				if (sgn(c.r-get_dist(c.p, p[j])) < 0) {
					c = {(p[i] + p[j]) / 2, get_dist(p[i], p[j]) / 2};
					
					for (int k = 0; k < j; k ++ ) {
						if (sgn(c.r-get_dist(c.p, p[k])) < 0) {
							c = get_circle(p[i], p[j], p[k]);
						}
					}
					
				}
			}
			
		}
	}
	
	return c;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++ ) scanf("%lf %lf", &p[i].x, &p[i].y);
	
	circle c = solve();
	
	printf("%.10lf\n", c.r);
	printf("%.10lf %.10lf\n", c.p.x, c.p.y);
	return 0;
}