#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-8;

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
	void input() {
		scanf("%lf %lf", &x, &y);
	}
	Point operator + (const Point& b) const {
		return Point(x + b.x,y + b.y);
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x,y - b.y);
	}
	Point operator / (const double &b) const {
		return Point(x/b, y/b);
	}
	double operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
	double operator ^ (const Point &b) const {
		return x*b.y - y*b.x;
	}
	bool operator < (Point b) const {
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0: x < b.x;
	}
	bool operator == (Point b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	Point rotate(Point p,double angle){
		Point v = (*this) - p;
		double c = cos(angle), s = sin(angle);
		return Point(p.x + v.x*c - v.y*s,p.y + v.x*s + v.y*c);
	}
};


double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

int n;
Point s, t;

int main() {
	scanf("%d", &n);
	s.input(); t.input();
	Point mid = (s + t) / 2;
	double rad = 2*PI/n;
	Point ans = s.rotate(mid, rad);
	printf("%.11f %.11f\n", ans.x, ans.y);
}
