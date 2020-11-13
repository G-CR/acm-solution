#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
using namespace std;

#define eps 1e-8

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
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
	
	// 判断直线相交的，无需要可以不用（如果不用相交返回交点，下面有一个只做判断的版本）
	// 返回pair second为0重合 为1平行 为2相交且first为交点
	pair <int, Point> operator &(const Line &b)const { 
		Point res = s;
		if(sgn((s-e)^(b.s-b.e)) == 0) {
			if(sgn((b.s-s)^(b.e-s)) == 0)
				return make_pair(0, res);//两直线重合
			else return make_pair(1, res);//两直线平行
		}
		double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
		res.x += (e.x - s.x)*t;
		res.y += (e.y - s.y)*t;
		return make_pair(2, res);//有交点
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
Point A, B, C, D;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lf %lf %lf %lf", &A.x, &A.y, &C.x, &C.y);
		scanf("%lf %lf %lf %lf", &B.x, &B.y, &D.x, &D.y);
		
		
		// 判断是否有平行于x轴的线段
		if(sgn(A.y-C.y) == 0 || sgn(B.y-D.y) == 0) {puts("0.00"); continue;}
		
		
		if(sgn(A.y-C.y) < 0) swap(A, C);
		if(sgn(B.y-D.y) < 0) swap(B, D);
		
		// 判断线段是否相交
		Line l1 = Line(A, C); Line l2 = Line(B, D);
		if(l1.seg_cross_seg(l2) == 0) {puts("0.00"); continue;}
		
		// 判断遮挡
		int ok1 = l1.seg_cross_seg(Line(Point(B.x, 100000), B));
		int ok2 = l2.seg_cross_seg(Line(Point(A.x, 100000), A));
		if(!(ok1 == 0 && ok2 == 0)) {puts("0.00"); continue;}
		
		pair <int, Point> t = l1 & l2;
		Point P = t.second;
		
		t = l1 & Line(B, Point(100000, B.y));
		Point P2 = t.second;
		double ans1 = fabs((B-P)^(P2-P))/2.0;
		
		t = l2 & Line(A, Point(100000, A.y));
		Point P1 = t.second;
		double ans2 = fabs((A-P)^(P1-P))/2.0;
		
		printf("%.2lf\n", min(ans1, ans2));
	}
}