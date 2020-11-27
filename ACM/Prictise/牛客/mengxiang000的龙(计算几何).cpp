#include <bits/stdc++.h> // nowcoder
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
};

struct Line { // 表示线段
	Point s, e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
	// 判断直线相交的，无需要可以不用（如果相交返回交点的版本，下面有一个只做判断的版本）
	// 返回pair second为0重合 为1平行 为2相交且first为交点
	pair <int, Point> operator & (const Line &b)const { 
		Point res = s;
		if(sgn((s-e)^(b.s-b.e)) == 0) {
			if(sgn((b.s-s)^(b.e-s)) == 0)
				return make_pair(0,res);//两直线重合
			else return make_pair(1,res);//两直线平行
		}
		double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
		res.x += (e.x - s.x)*t;
		res.y += (e.y - s.y)*t;
		return make_pair(2,res);//有交点
	}
};

// 点P在直线AB上的投影
Point GetLineProjection(Point P, Point A, Point B) {
	Point v = B - A;
	double t = (v * (P-A)) / (v*v);
	return A + Point(v.x*t, v.y*t);
}

Point home, school;
double A, B, C;

int main() {
	scanf("%lf %lf %lf %lf %lf %lf %lf", &home.x, &home.y, &school.x, &school.y, &A, &B, &C);
	
	Point p1, p2;
	
	if(!A) {
		p1 = Point(0, C/B); p2 = Point(1, C/B);
	}
	else if(!B) {
		p1 = Point(C/A, 1); p2 = Point(C/A, 0);
	}
	else if(!C) {
		p1 = Point(0, 0); p2 = Point(-1, A/B); 
	}
	else {
		p1 = Point(1, (C-A)/B); p2 = Point((C-B)/A ,1);
	}
	
	Line river = Line(p1, p2);
	Point ty = GetLineProjection(home, p1, p2);
	Point dc = Point(2*ty.x-home.x, 2*ty.y-home.y); 
	
	Point ans = (Line(dc, school) & river).second;
	printf("%.12lf %.12lf\n", ans.x, ans.y);
}