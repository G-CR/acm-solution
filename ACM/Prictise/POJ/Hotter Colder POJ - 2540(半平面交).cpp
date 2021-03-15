#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const int maxp = 100;

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point {
	double x, y;
	Point() {}
	Point(double _x, double _y) {
		x = _x;
		y = _y;
	}
	void input() {
		scanf("%lf %lf", &x, &y);
	}
	Point operator + (const Point &b) const {
		return Point(x+b.x, y+b.y);
	}
	Point operator / (const double &b) const {
		return Point (x/2, y/2);
	}
	bool operator == (const Point &b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	Point operator - (const Point &b) const {
		return Point(x-b.x, y-b.y);
	}
	double operator ^ (const Point &b) const {
		return x*b.y - y*b.x;
	}
};


struct Line {
	Point s, e;
	Line() {}
	Line(Point _s, Point _e) {
		s = _s;
		e = _e;
	}
	bool operator == (Line v) {
		return (s == v.s) && (e == v.e);
	}
	
	bool parallel(Line v) {
		return sgn((e-s) ^ (v.e-v.s)) == 0;
	}
	void adjust() {swap(s, e);}
	Point crosspoint(Line v) {
		double a1 = (v.e-v.s) ^ (s-v.s);
		double a2 = (v.e-v.s) ^ (e-v.s);
		return Point ((s.x*a2-e.x*a1)/(a2-a1), (s.y*a2-e.y*a1)/(a2-a1));
	}
	//`点和直线关系`
	//`1  在左侧`
	//`2  在右侧`
	//`3  在直线上`
	int relation(Point p){
		int c = sgn((p-s)^(e-s));
		if(c < 0)return 1;
		else if(c > 0)return 2;
		else return 3;
	}
};

struct polygon {
	int n;
	Point p[maxp];
	Line l[maxp];
	
	void getline() {
		for(int i = 0;i < n; i++) {
			l[i] = Line(p[i], p[(i+1)%n]);
		}
	}
	
	double getarea() {
		double sum = 0;
		for(int i = 0;i < n;i++){
			sum += (p[i]^p[(i+1)%n]);
		}
		return fabs(sum)/2;
	}
};

struct Vector: public Point {
	Vector(){}
	Vector(double a,double b) {
		x=a;    y=b;
	}
	Vector(Point _a,Point _b) { //a->b
		
		double dx=_b.x-_a.x;
		double dy=_b.y-_a.y;
		x=dx;   y=dy;
	}
	Vector(Line v) {
		double dx=v.e.x-v.s.x;
		double dy=v.e.y-v.s.y;
		x=dx;   y=dy;
	}
	double length() {
		return (sqrt(x*x+y*y));
	}
	Vector Normal() { //返回this的单位长度的法向量
		double L=sqrt(x*x+y*y);
		Vector Vans=Vector(-y/L,x/L);
		return Vans;
	}
};

struct halfplane: public Line {
	double angle;
	halfplane() {}
	halfplane(Point _s, Point _e) {
		s = _s;
		e = _e;
	}
	halfplane(Line v) {
		s = v.s;
		e = v.e;
	}
	void calcangle() {
		angle = atan2(e.y-s.y, e.x-s.x);
	}
	bool operator < (const halfplane &b) const {
		return angle < b.angle;
	}
};

struct halfplanes {
	int n;
	halfplane hp[maxp];
	Point p[maxp];
	int que[maxp];
	int st, ed;
	void push(halfplane tmp) {
		hp[n++] = tmp;
	}
	
	void unique() {
		int m = 1;
		for(int i = 1; i < n; i++) {
			if(sgn(hp[i].angle - hp[i-1].angle) != 0)
				hp[m++] = hp[i];
			else if(sgn( (hp[m-1].e - hp[m-1].s) ^ (hp[i].s-hp[m-1].s)) > 0)
				hp[m-1] = hp[i];
		}
		n = m;
	}
	
	bool halfpalneinsert() {
		for(int i = 0; i < n; i++) hp[i].calcangle();
		sort(hp, hp+n);
		unique();
		que[st = 0] = 0;
		que[ed = 1] = 1;
		p[1] = hp[0].crosspoint(hp[1]);
		for(int i = 2; i < n; i++) {
			while(st<ed && sgn((hp[i].e-hp[i].s) ^ (p[ed]-hp[i].s)) < 0) ed--;
			while(st<ed && sgn((hp[i].e-hp[i].s) ^ (p[st+1]-hp[i].s)) < 0) st++;
			que[++ed] = i;
			if(hp[i].parallel(hp[que[ed-1]])) return false;
			p[ed] = hp[i].crosspoint(hp[que[ed-1]]);
		}
		
		while(st<ed && sgn((hp[que[st]].e - hp[que[st]].s) ^ (p[ed]-hp[que[st]].s)) < 0) ed--;
		while(st<ed && sgn((hp[que[ed]].s - hp[que[ed]].s) ^ (p[st+1]-hp[que[ed]].s)) < 0) st++;
		
		if(st+1 >= ed) return false;
		return true;
	}
	
	void getconvex(polygon &con) {
		p[st] = hp[que[st]].crosspoint(hp[que[ed]]);
		con.n = ed-st+1;
		for(int j = st, i = 0; j <= ed; i++, j++)
			con.p[i] = p[j];
	}
};

Point now, pre;
string t;
halfplanes hf;
Vector vc;

int main() {
	hf.push(halfplane(Point(0, 0), Point(10, 0)));
	hf.push(halfplane(Point(10, 0), Point(10, 10)));
	hf.push(halfplane(Point(10, 10), Point(0, 10)));
	hf.push(halfplane(Point(0, 10), Point(0, 0)));
	
	pre = {0, 0};
	bool ok = 1;
	while(~scanf("%lf %lf", &now.x, &now.y)) {
		cin >> t;
		if(t == "Same") ok = 0;
		if(!ok) {
			puts("0.00");
			continue;
		}
		
		vc = Vector(pre, now);
		vc = vc.Normal();
		Point mid = (pre + now) / 2;
		Point res = mid + vc;
		Line zcx = Line(mid, res);
		
		if(t == "Hotter" && zcx.relation(now) != 1) {
			zcx.adjust();
		}
		else if(t == "Colder" && zcx.relation(pre) != 1) {
			zcx.adjust();
		}
		hf.push(zcx);
		ok = hf.halfpalneinsert();
		if(!ok) puts("0.00");
		else {
			polygon ans;
			hf.getconvex(ans);
			printf("%.2f\n", ans.getarea());
		}
		
		pre = now;
	}
}