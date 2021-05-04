#include <bits/stdc++.h>
using namespace std;

int _;

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
	double rad(Point a,Point b){
		Point p = *this;
		return fabs(atan2( fabs((a-p)^(b-p)),(a-p)*(b-p) ));
	}
};

double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

struct circle{
	Point p;//圆心
	double r;//半径
	circle(){}
	circle(Point _p,double _r){
		p = _p;
		r = _r;
	}
	circle(double x,double y,double _r){
		p = Point(x,y);
		r = _r;
	}
	double circumference(){
		return 2*PI*r;
	}
};

Point o, a, b;

int main() {
	int cas = 0;
	scanf("%d", &_); while(_--) {
		o.input(); a.input(); b.input();
		double r = dist(o, a);
		circle c (o, r);
		double rad = o.rad(a, b);
		double ans = c.circumference() * rad / (2 * PI);
		printf("Case %d: %.10f\n", ++cas, min(ans, c.circumference()-ans));
	}
}