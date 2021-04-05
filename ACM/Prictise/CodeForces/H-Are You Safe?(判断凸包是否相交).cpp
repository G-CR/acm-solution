#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-8;

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point {
	double x, y;
	Point () {}
	Point (double _x, double _y) {
		x = _x; y = _y;
	}
	void input() {
		scanf("%lf %lf", &x, &y);
	}
	Point operator + (const Point &b) const {
		return Point(x+b.x, y+b.y);
	}
	Point operator - (const Point &b) const {
		return Point(x-b.x, y-b.y);
	}
	double operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
	double operator ^ (const Point &b) const {
		return x*b.y - y*b.x;
	}
	bool operator < (Point b) const {
		return sgn(x-b.x) == 0? sgn(y-b.y) < 0: x < b.x;
	}
	bool operator == (Point b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
};


double dist(Point a, Point b) {
	return sqrt((b-a) * (b-a));
}

struct Line {
	Point s, e;
	Line() {}
	Line(Point _s, Point _e) {
		s = _s; e = _e;
	}
};


bool Onseg(Point p, Line L) {
	return 
		sgn((L.s-p) ^ (L.e-p)) == 0 &&
		sgn((p.x - L.s.x) * (p.x - L.e.x)) <= 0 &&
		sgn((p.y - L.s.y) * (p.y - L.e.y)) <= 0;
}

const int N = 100;

struct polygon {
	int n;
	Point p[N];
	Line l[N];
	void input(int _n) {
		n = _n;
		for(int i = 0; i < n; i++) {
			p[i].input();
		}
	}
	struct cmp {
		Point p;
		cmp(const Point &p0) {p = p0;}
		bool operator() (const Point &aa, const Point &bb) {
			Point a = aa, b = bb;
			int d = sgn((a-p) ^ (b-p));
			if(d == 0) {
				return sgn(dist(a, p)-dist(b, p) < 0);
			}
			return d > 0;
		}
	};
	
	void norm() {
		Point mi = p[0];
		for(int i = 1; i < n; i++) mi = min(mi, p[i]);
		sort(p, p+n, cmp(mi));
	}
	
	void getconvex(polygon &convex) {
		sort(p, p+n);
		convex.n = n;
		for(int i = 0; i < min(n, 2); i++) {
			convex.p[i] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))
			convex.n--;
		if(n <= 2) return;
		int &top = convex.n;
		top = 1;
		for(int i = 2; i < n; i++) {
			while(top && sgn((convex.p[top]-p[i]) ^ (convex.p[top-1]-p[i])) <= 0)
				top--;
			convex.p[++top] = p[i];
		}
		
		int temp = top;
		convex.p[++top] = p[n-2];
		for(int i = n-3; i >= 0; i--) {
			while(top != temp && sgn((convex.p[top]-p[i]) ^ (convex.p[top-1]-p[i])) <= 0)
				top--;
			convex.p[++top] = p[i];
		}
		
		if(convex.n == 2 && (convex.p[0] == convex.p[1])) convex.n--;
		convex.norm();
	}
};

int inConvexPoly(Point a, Point p[], int n) {
	for(int i = 0; i < n; i++) {
		if(sgn((p[i]-a) ^ (p[(i+1)%n]-a)) < 0) return -1;
		else if(Onseg(a, Line(p[i], p[(i+1)%n]))) return 0;
	}
	return 1;
}

int _, pn, n;
Point p;
polygon poly, res;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d %d", &pn, &n);
		poly.input(pn);
		poly.getconvex(res);
		printf("Case %d\n", ++cas);
		for(int i = 0; i < res.n; i++) {
			printf("%.0f %.0f\n", res.p[i].x, res.p[i].y);
		} printf("%.0f %.0f\n", res.p[0].x, res.p[0].y);
		
		for(int i = 0; i < n; i++) {
			p.input();
			printf("%.0f %.0f is ", p.x, p.y);
			if(~inConvexPoly(p, res.p, res.n)) {
				puts("unsafe!");
			}
			else puts("safe!");
		}
		puts("");
	}
}