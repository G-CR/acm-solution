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

bool OnSeg(Point P,Line L) {
	return
	sgn((L.s-P)^(L.e-P)) == 0 &&
	sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
	sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

int inConvexPoly(Point a,Point p[],int n) {
	for(int i = 0;i < n;i++) {
		if(sgn((p[i]-a)^(p[(i+1)%n]-a)) < 0)return -1;
		else if(OnSeg(a,Line(p[i],p[(i+1)%n])))return 0;
	}
	return 1;
}

double l, r, h;
Point p[7], poly[5];
Line s[4];

void init() {
	p[1] = Point(l, h); p[2] = Point(r, h);
	scanf("%lf %lf %lf", &l, &r, &h);
	p[3] = Point(l, h); p[4] = Point(r, h);
	scanf("%lf %lf %lf", &l, &r, &h);
	p[5] = Point(l, h); p[6] = Point(r, h);
	
	s[1] = Line(p[1], p[2]);
	s[2] = Line(p[3], p[4]);
	s[3] = Line(p[5], p[6]);
	
	poly[0] = p[1]; poly[1] = p[2]; poly[2] = p[6]; poly[3] = p[5];
}

int main() {
	while(~scanf("%lf %lf %lf", &l, &r, &h)) {
		init();
		
//		for(int i = 1;i <= 6; i++) {
//			printf("%.0lf %.0lf\n", p[i].x, p[i].y);
//		}
		
		bool ok = 0;
		if(inConvexPoly(p[3], poly, 4) >= 0 || inConvexPoly(p[4], poly, 4) >= 0) ok = 1;
		
//		printf("ok = %d\n", ok);
		Line l1 = Line(s[1].s, s[3].s);
		Line l2 = Line(s[3].e, s[3].e);
		
		if(s[2].seg_cross_seg(l1) || s[2].seg_cross_seg(l2)) ok = 1;
//		printf("ok = %d\n", ok);
		
		if(ok) puts("Yes");
		else puts("No");
	}
}