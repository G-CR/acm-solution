#include <bits/stdc++.h>
using namespace std;

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
};

struct Line { // 表示线段
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
	
	// 判断直线相交的，无需要可以不用（如果相交返回交点的版本，下面有一个只做判断的版本）
	// 返回pair second为0重合 为1平行 为2相交且first为交点
	pair <int, Point> operator &(const Line &b)const { 
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
Point GetLineProjection(Point P,Point A,Point B) {
	Point v = B - A;
	double t = (v * (P-A)) / (v*v);
	return A + Point(v.x*t, v.y*t);
}

//两点距离
double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}


Point p[4], tree;
Line l[4];

//重心：三条中线的交点
Point centroid(Point A, Point B, Point C) {
	Point res = A + B + C;
	return Point(res.x/3, res.y/3);
}

//内切圆圆心
Point incenter(Point A, Point B, Point C) {
	double a = dist(B, C);
	double b = dist(A, C);
	double c = dist(A, B);
	double S = a + b + c;
	double x = (a * A.x + b * B.x + c * C.x) / S;
	double y = (a * A.y + b * B.y + c * C.y) / S;
	return Point(x, y);
}

//外接圆圆心
Point circumcenter(Point A, Point B, Point C) {
	double x1 = A.x, y11 = A.y;
	double x2 = B.x, y2 = B.y;
	double x3 = C.x, y3 = C.y;
	
	double a1 = 2 * (x2 - x1);
	double b1 = 2 * (y2 - y11);
	double c1 = x2*x2 + y2*y2 - x1*x1 - y11*y11;
	
	double a2 = 2 * (x3-x2);
	double b2 = 2 * (y3-y2);
	double c2 = x3*x3 + y3*y3 - x2*x2 - y2*y2;
	
	double x = (c1*b2 - c2*b1) / (a1*b2 - a2*b1);
	double y = (a1*c2 - a2*c1) / (a1*b2 - a2*b1);
	
	return Point(x,y);
}

// 垂心：三边垂直平分线的交点
Point orthocenter(Point A, Point B, Point C) {
	Point cent = centroid(A, B, C);
	cent = Point(cent.x * 3.0, cent.y * 3);
	
	Point circ = circumcenter(A, B, C);
	circ = Point(circ.x * 2.0, circ.y * 2.0);
	return cent - circ;
}

int main() {
	for(int i = 1;i <= 3; i++) {
		scanf("%lf %lf", &p[i].x, &p[i].y);
	}
	scanf("%lf %lf", &tree.x, &tree.y);
	
	// 正交中心
	Point zjzx = orthocenter(p[1], p[2], p[3]);
	
	// 重心
	Point zx = centroid(p[1], p[2], p[3]);
	
	// 内心
	Point nx = incenter(p[1], p[2], p[3]);
	
	// 外心
	Point wx = circumcenter(p[1], p[2], p[3]);
	
	if(tree == zjzx || tree == zx || tree == nx || tree == wx) {
		puts("Yes");
	}
	else puts("No");
}