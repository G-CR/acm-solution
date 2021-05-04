#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1);
const double eps = 1e-8;

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point {
	double x, y;
	Point () {}
	Point(double _x, double _y) {
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
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0 : x < b.x;
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
	void input() {
		s.input();
		e.input();
	}
};

Point NearestPointToLineSeg(Point P, Line L) {
	Point result;
	double t = ((P-L.s)*(L.e-L.s)) / ((L.e-L.s)*(L.e-L.s));
	if(t >= 0 && t <= 1) {
		result.x = L.s.x + (L.e.x - L.s.x) * t;
		result.y = L.s.y + (L.e.y - L.s.y) * t;
	}
	else {
		if(dist(P, L.s) < dist(P, L.e))
			result = L.s;
		else result = L.e;
	}
	return result;
}

Point p1[3], p2[3];
Line tri1[3], tri2[3];

void read() {
	for(int i = 0; i < 3; i++) p1[i].input();
	for(int i = 0; i < 3; i++) tri1[i] = Line(p1[i], p1[(i+1)%3]);
	
	for(int i = 0; i < 3; i++) p2[i].input();
	for(int i = 0; i < 3; i++) tri2[i] = Line(p2[i], p2[(i+1)%3]);
}


int main() {
	int _; scanf("%d", &_); while(_--) {
		read();
		double ans = 1e18;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				Point now = NearestPointToLineSeg(p1[i], tri2[j]);
				ans = min(ans, dist(now, p1[i]));
			}
		}
		
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				Point now = NearestPointToLineSeg(p2[i], tri1[j]);
				ans = min(ans, dist(now, p2[i]));
			}
		}
		
		printf("%.10f\n", 0.5*ans);
	}
}