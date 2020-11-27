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
	
	int relation(Point p){
		int c=sgn((p-s)^(p-e));
		if(c<0)return 1;
		else if(c>0) return 2;
		else return 3;
	}
	bool parallel(Line v){
		return sgn((e-s)^(v.e-v.s))==0;
	}
	//直线与直线相交判断
	//0 平行
	//1 重合
	//2 相交
	int line_cross_line(Line v){
		if((*this).parallel(v))
		return v.relation(s)==3;
		return 2;
	}
};

bool inter(Line l1,Line l2) {
	return
	max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
	max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
	max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
	max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
	sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
	sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

bool OnSeg(Point P,Line L) {
	return
	sgn((L.s-P)^(L.e-P)) == 0 &&
	sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
	sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

int inPoly(Point p,Point poly[],int n) {
	int cnt;
	Line ray,side;
	cnt = 0;
	ray.s = p;
	ray.e.y = p.y;
	ray.e.x = -1000000.0;//-INF,注意取值防止越界

	for(int i = 0;i < n;i++) {
		side.s = poly[i];
		side.e = poly[(i+1)%n];

		if(OnSeg(p,side))return 0;

		//如果平行轴则不考虑
		if(sgn(side.s.y - side.e.y) == 0)
			continue;

		if(OnSeg(side.s,ray)) {
			if(sgn(side.s.y - side.e.y) > 0)cnt++;
		}
		else if(OnSeg(side.e,ray)) {
			if(sgn(side.e.y - side.s.y) > 0)cnt++;
		}
		else if(inter(ray,side)) cnt++;
	}
	if(cnt % 2 == 1) return 1;
	else return -1;
}

int _;

int main() {
	scanf("%d", &_);
	while(_--) {
		Point p[3];
		for(int i = 0;i < 3; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		Line l1 = Line(p[0], p[1]);
		Line l2 = Line(p[1], p[2]);
		if(l1.line_cross_line(l2) == 1) {puts("NO"); continue;}
		
		Point cen = Point(0, 0);
		if(inPoly(cen, p, 3) == 1) {
			puts("YES");
		}
		else puts("NO");
	}
}