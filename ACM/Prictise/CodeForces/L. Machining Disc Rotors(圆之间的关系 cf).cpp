#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-9;

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
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0 : x < b.x;
	}
	bool operator == (Point b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	double len() {
		return hypot(x,y);
	}
	Point trunc(double r) {
		double l = len();
		if(!sgn(l))return *this;
		r /= l;
		return Point(x*r,y*r);
	}
	Point rotleft() {
		return Point(-y,x);
	}
	Point rotright() {
		return Point(y,-x);
	}
};

double dist(Point a, Point b) {
	return sqrt((b-a) * (b-a));
}

struct circle {
	Point p;
	double r;
	circle() {}
	circle(Point _p, double _r) {
		p = _p;
		r = _r;
	}
	void input() {
		p.input();
		scanf("%lf", &r);
	}
	
	bool operator == (circle v){
		return (p==v.p) && sgn(r-v.r)==0;
	}
	bool operator < (circle v)const{
		return ((p<v.p)||((p==v.p)&&sgn(r-v.r)<0));
	}
	
	int relation(Point b) {
		double dst = dist(b, p);
		if(sgn(dst-r) < 0) return 2;
		else if(sgn(dst-r) == 0) return 1;
		return 0;
	}
	
	int relationcircle(circle v) {
		double d = dist(p, v.p);
		if(sgn(d-r-v.r) > 0) return 5;
		if(sgn(d-r-v.r) == 0) return 4;
		double l = fabs(r-v.r);
		if(sgn(d-r-v.r)<0 && sgn(d-l)>0)return 3;
		if(sgn(d-l)==0)return 2;
		if(sgn(d-l)<0)return 1;
	}
	
	int pointcrosscircle(circle v,Point &p1,Point &p2) {
		int rel = relationcircle(v);
		if(rel == 1 || rel == 5)return 0;
		double d = dist(p, v.p);
		double l = (d*d+r*r-v.r*v.r)/(2*d);
		double h = sqrt(r*r-l*l);
		Point tmp = p + (v.p-p).trunc(l);
		p1 = tmp + ((v.p-p).rotleft().trunc(h));
		p2 = tmp + ((v.p-p).rotright().trunc(h));
		if(rel == 2 || rel == 4)
			return 1;
		return 2;
	}
};


int _, n;
double R, r;
Point cen, p1, p2, res[1003];
circle C, cir[1003];

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d %lf", &n, &R);
		C = circle(Point(0, 0), R);
		int num = 0;
		for(int i = 0; i < n; i++) {
			cen.input(); scanf("%lf", &r);
			cir[i] = circle(cen, r);
			int cnt = C.pointcrosscircle(cir[i], p1, p2);
			if(cnt == 2) {
				res[num++] = p1;
				res[num++] = p2;
			}
		}
		double ma = 0;
		if(num < 2) ma = 2*R;
		
		if(sgn(ma) == 0) {
			for(int i = 0; i < num; i++) {
				Point dc = Point(-1.0*res[i].x, -1.0*res[i].y);
				bool ok = 1;
				for(int j = 0; j < n; j++) {
					if(cir[j].relation(dc) == 2) {
						ok = 0;
						break;
					}
				}
				
				if(ok) {
					ma = 2*R;
					break;
				}
			}
		}
		
		if(sgn(ma) == 0) {
			for(int i = 0; i < num; i++) {
				for(int j = i+1; j < num; j++) {
					ma = max(ma, dist(res[i], res[j]));
				}
			}
		}
		
		printf("Case #%d: %.15f\n", ++cas, ma);
	}
}