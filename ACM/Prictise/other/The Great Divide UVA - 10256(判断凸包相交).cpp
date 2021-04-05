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
	Point (){}
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
	double operator ^ (const Point b) const {
		return x*b.y - y*b.x;
	}
	bool operator < (Point b) const {
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0 : x < b.x;
	}
	bool operator == (Point b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
};

double dist(Point a, Point b) {
	return sqrt((b-a)*(b-a));
}

struct Line {
	Point s, e;
	Line() {}
	Line(Point _s, Point _e) {
		s = _s; e = _e;
	}
	
	int seg_cross_seg(Line v) {
		int d1 = sgn((e-s) ^ (v.s-s));
		int d2 = sgn((e-s) ^ (v.e-s));
		int d3 = sgn((v.e-v.s) ^ (s-v.s));
		int d4 = sgn((v.e-v.s) ^ (e-v.s));
		if((d1^d2) == -2 && (d3^d4) == -2) return 2;
		return
			(d1 == 0 && sgn((v.s-s) * (v.s-e)) <= 0) ||
			(d2 == 0 && sgn((v.e-s) * (v.e-e)) <= 0) ||
			(d3 == 0 && sgn((s-v.s) * (s-v.e)) <= 0) ||
			(d4 == 0 && sgn((e-v.s) * (e-v.e)) <= 0);
	}
};

bool Onseg(Point P,Line L) {
	return
	sgn((L.s-P)^(L.e-P)) == 0 &&
	sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
	sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

const int maxp = 1000;
struct polygon {
	int n;
	Point p[maxp];
	Line l[maxp];
	void input(int _n) {
		n = _n;
		for(int i = 0; i < n; i++)
			p[i].input();
	}
	void getline() {
		for(int i = 0; i < n; i++) {
			l[i] = Line(p[i], p[(i+1)%n]);
		}
	}
	
	struct cmp {
		Point p;
		cmp(const Point &p0) {p = p0;}
		bool operator() (const Point &aa, const Point &bb) {
			Point a = aa, b = bb;
			int d = sgn((a-p) ^ (b-p));
			if(d == 0) {
				return sgn(dist(a, p) - dist(b, p)) < 0;
			}
			return d > 0;
		}
	};
	
	void norm() {
		Point mi = p[0];
		for(int i = 1; i < n; i++) mi = min(mi, p[i]);
		sort(p, p+n, cmp(mi));
	}
	
	void Graham(polygon &convex){
		norm();
		int &top = convex.n;
		top = 0;
		if(n == 1){
			top = 1;
			convex.p[0] = p[0];
			return;
		}
		if(n == 2){
			top = 2;
			convex.p[0] = p[0];
			convex.p[1] = p[1];
			if(convex.p[0] == convex.p[1])top--;
			return;
		}
		convex.p[0] = p[0];
		convex.p[1] = p[1];
		top = 2;
		for(int i = 2;i < n;i++){
			while( top > 1 && sgn((convex.p[top-1]-convex.p[top-2])^(p[i]-convex.p[top-2])) <= 0 )
				top--;
			convex.p[top++] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1]))convex.n--;//特判
	}
};

int inConvexPoly(Point a,Point p[],int n) {
	for(int i = 0;i < n;i++) {
		if(sgn((p[i]-a)^(p[(i+1)%n]-a)) < 0) return -1;
		else if(Onseg(a,Line(p[i],p[(i+1)%n]))) return 0;
	}
	return 1;
}

bool isPointInPolygon(Point p, Point* res, int cnt) {
	int wn = 0;
	for (int i = 0; i < cnt; i++) {
		if (res[i] == p || res[(i + 1) % cnt] == p || Onseg(p, Line(res[i], res[(i + 1) % cnt])))
			return 1;
		int k = sgn((res[(i + 1) % cnt] - res[i]) ^ (p - res[i]));
		int d1 = sgn(res[i].y - p.y);
		int d2 = sgn(res[(i + 1) % cnt].y - p.y);
		if (k > 0 && d1 <= 0 && d2 > 0)
			wn++;
		if (k < 0 && d2 <= 0 && d1 > 0)
			wn--;
	}
	if (wn)
		return 1;
	return 0;
}

int n, m;
polygon p1, p2, r1, r2;

bool check1() {
	for(int i = 0; i < r1.n; i++)
		if(isPointInPolygon(r1.p[i], r2.p, r2.n))
			return 0;
		
	for(int i = 0; i < r2.n; i++)
		if(isPointInPolygon(r2.p[i], r1.p, r1.n))
			return 0;
	return 1;
}

bool check2() {
	r1.getline(); r2.getline();
	for(int i = 0; i < r1.n; i++) {
		for(int j = 0; j < r2.n; j++) {
			if(r1.l[i].seg_cross_seg(r2.l[j]) > 0)
				return 0;
		}
	}
	
	return 1;
}


int main() {
	while(~scanf("%d %d", &n, &m) && n) {
		p1.input(n); p2.input(m);
		p1.Graham(r1); p2.Graham(r2);
		if(check1() && check2()) puts("Yes");
		else puts("No");
	}
}