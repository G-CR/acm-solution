#include <bits/stdc++.h>
using namespace std;

struct Point { // 表示点
	double x, y;
	Point(){}
	Point(double _x,double _y) {
		x = _x; y = _y;
	}
	Point operator + (const Point& b) const {
		return Point(x + b.x,y + b.y);
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x,y - b.y);
	}
	double operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
};

struct Line { // 表示线段
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
};

// 点P在直线AB上的投影
Point GetLineProjection(Point P,Point A,Point B) {
	Point v = B - A;
	double t = (v * (P-A)) / (v*v);
	return A + Point(v.x*t, v.y*t);
}

int _;

int main() {
	scanf("%d", &_);
	Point P, U, V;
	while(_--) {
		scanf("%lf %lf %lf %lf %lf %lf", &P.x, &P.y, &U.x, &U.y, &V.x, &V.y);
		Point ans = GetLineProjection(P, U, V);
		printf("%.7lf %.7lf\n", ans.x, ans.y);
	}
}