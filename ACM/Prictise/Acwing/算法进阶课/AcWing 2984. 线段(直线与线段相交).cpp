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
};


int _, n;
Line l[102];
Point p[202];

// 三个点计算叉积 p0p1 ^ p0p2
double xmult(Point p0,Point p1,Point p2) { 
	return (p1-p0)^(p2-p0);
}

// 判断直线l1和线段l2是否相交
bool Seg_inter_line(Line l1, Line l2) { 
	return sgn(xmult(l2.s,l1.s,l1.e))*sgn(xmult(l2.e,l1.s,l1.e)) <= 0;
}

bool check(Line now) {
	for(int i = 1;i <= n; i++) {
		if(!Seg_inter_line(now, l[i])) return 0;
	}
	return 1;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lf %lf %lf %lf", &p[i*2-1].x, &p[i*2-1].y, &p[i*2].x, &p[i*2].y);
			l[i] = Line(p[i*2-1], p[i*2]);
		}
		
		bool ok = 0;
		for(int i = 1; i <= n*2; i++) {
			for(int j = i+1; j <= n*2; j++) {
				if(p[i] == p[j]) continue;
				if(check(Line(p[i], p[j]))) {
					ok = 1;
					break;
				}
			}
			if(ok) break;
		}
		
		if(ok) puts("Yes!");
		else puts("No!");
	}
}