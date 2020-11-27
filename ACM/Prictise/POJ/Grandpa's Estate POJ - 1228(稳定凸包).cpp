#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
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
};

//*判断点在线段上
bool OnSeg(Point P,Line L) {
	return
	sgn((L.s-P)^(L.e-P)) == 0 &&
	sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
	sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

//两点距离
double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

// 三个点计算叉积 p0p1 ^ p0p2
double xmult(Point p0,Point p1,Point p2) { 
	return (p1-p0)^(p2-p0);
}

const int maxp = 1e3+3;

struct polygon {
	int n;
	Point p[maxp];
	struct cmp {
		Point p;
		cmp(const Point &p0) {p = p0;}
		bool operator() (const Point &aa, const Point &bb) {
			Point a = aa, b = bb;
			int d = sgn((a-p)^(b-p));
			if(d == 0) {
				return sgn(dist(a,p)-dist(b,p)) < 0;
			}
			return d > 0;
		}
	};
	
	void norm() {
		Point mi = p[0];
		for(int i = 1;i < n; i++) mi = min(mi, p[i]);
		sort(p, p+n, cmp(mi));
	}
	
	void Graham(polygon &convex) {
		norm();
		int &top = convex.n;
		top = 0;
		
		convex.p[0] = p[0];
		convex.p[1] = p[1];
		top = 2;
		for(int i = 2;i < n; i++) {
			while(top > 1 && sgn((convex.p[top-1]-convex.p[top-2])^(p[i]-convex.p[top-2])) < 0) top--;
			convex.p[top++] = p[i];
		}
		
		// 找到在最后一条边上的所有点
		Point fi = convex.p[0], se = convex.p[top-1];
		Line la = Line(fi, se);
		for(int i = 0;i < n; i++) {
			if(p[i] == fi || p[i] == se) continue;
			if(OnSeg(p[i], la)) {
				convex.p[top++] = p[i];
			}
		}
	}
};

int _, n;
polygon in, poly;

bool judge() { 
	for(int i = 1;i < poly.n; i++) {
		if((xmult(poly.p[i-1],poly.p[(i+1)%poly.n],poly.p[i]))!=0&&(xmult(poly.p[i],poly.p[(i+2)%poly.n],poly.p[(i+1)%poly.n]))!=0)//判断每条边是否有至少三个点;
		return false;
	}
	return true;
}


int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		in.n = n;
		for(int i = 0;i < n; i++) {
			scanf("%lf %lf", &in.p[i].x, &in.p[i].y);
		}
		if(n < 6) {
			puts("NO");
			continue;
		}
		in.Graham(poly);
		
		if(judge()) puts("YES");
		else puts("NO");
	}
}