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
	//线段与线段相交判断
	//2 规范相交
	//1 非规范相交
	//0 不相交
	int seg_cross_seg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		int d3 = sgn((v.e-v.s)^(s-v.s));
		int d4 = sgn((v.e-v.s)^(e-v.s));
		if((d1^d2)==-2&&(d3^d4)==-2) return 2;
		return (d1==0 &&sgn((v.s-s)*(v.s-e))<=0)||
		(d2==0 &&sgn((v.e-s)*(v.e-e))<=0)||
		(d3==0 &&sgn((s-v.s)*(s-v.e))<=0)||
		(d4==0 &&sgn((e-v.s)*(e-v.e))<=0);
	}
};

int _;
Point p[5];

int main() {
	scanf("%d", &_);
	while(_--) {
		for(int i = 1;i <= 4; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		Line l1 = Line(p[1], p[2]);
		Line l2 = Line(p[3], p[4]);
		
		int check = l1.seg_cross_seg(l2);
		if(check == 0) puts("No");
		else puts("Yes");
	}
}