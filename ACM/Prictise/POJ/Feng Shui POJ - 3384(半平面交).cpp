#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

const double eps = 1e-8;
const int maxp = 103;

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point {
	double x, y;
	Point() {}
	Point (double _x,  double _y) {
		x = _x;
		y = _y;
	}
	void input() {
		scanf("%lf %lf", &x, &y);
	}
	
	bool operator == (Point b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	Point operator - (const Point &b) const {
		return Point(x-b.x, y-b.y);
	}
	double operator ^(const Point &b) const {
		return x*b.y - y*b.x;
	}
	double operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
	Point add(Point p) {
		return Point(x+p.x,y+p.y);
	}
	Point mul(double b) {
		return Point(x*b, y*b);
	}
};

//两点距离
double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

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
		return sgn((e-s)^(v.e-v.s)) == 0;
	}
	
	Point crosspoint(Line v) {
		double a1 = (v.e-v.s) ^ (s-v.s);
		double a2 = (v.e-v.s) ^ (e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1), (s.y*a2-e.y*a1)/(a2-a1));
	}
};

struct polygon {
	int n;
	Point p[maxp];
	Line l[maxp];
	void input(int _n) {
		n = _n;
		for(int i = 0;i < n; i++) {
			p[i].input();
		}
	}
	
	void getline() {
		for(int i = 0;i < n; i++) {
			l[i] = Line(p[i], p[(i+1)%n]);
		}
	}
};

struct Vector: public Point {
	Vector() {}
	Vector(double a, double b) {
		x = a; y = b;
	}
	Vector(Point _a, Point _b) {
		double dx = _b.x - _a.x;
		double dy = _b.y - _a.y;
		x = dx; y = dy;
	}
	Vector(Line v) {
		double dx = v.e.x - v.s.x;
		double dy = v.e.y - v.s.y;
		x = dx; y = dy;
	}
	
	double length() {
		return sqrt(x*x+y*y);
	}
	
	Vector Normal() {
		double L = sqrt(x*x+y*y);
		Vector vans = Vector(-y/L, x/L);
		return vans;
	}
};

struct halfplane: public Line {
	double angle;
	halfplane(){}
	// 表示向量s->e逆时针(左侧)的半平面
	halfplane(Point _s,Point _e) {
		s = _s;
		e = _e;
	}
	halfplane(Line v) {
		s = v.s;
		e = v.e;
	}
	void calcangle() {
		angle = atan2(e.y-s.y,e.x-s.x);
	}
	bool operator < (const halfplane &b) const{
		return angle < b.angle;
	}
};

struct halfplanes {
	int n;
	halfplane hp[maxp];
	Point p[maxp];
	int que[maxp];
	int st,ed;
	void push(halfplane tmp) {
		hp[n++] = tmp;
	}
	//去重
	void unique() {
		int m = 1;
		for(int i = 1;i < n;i++){
			if(sgn(hp[i].angle-hp[i-1].angle) != 0)
				hp[m++] = hp[i];
			else if(sgn( (hp[m-1].e-hp[m-1].s)^(hp[i].s-hp[m-1].s) ) > 0)
				hp[m-1] = hp[i];
		}
		n = m;
	}
	
	bool halfplaneinsert(){
		for(int i = 0;i < n;i++) hp[i].calcangle();
		sort(hp,hp+n);
		unique();
		que[st=0] = 0;
		que[ed=1] = 1;
		p[1] = hp[0].crosspoint(hp[1]);
		for(int i = 2;i < n;i++){
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[ed]-hp[i].s))<0)ed--;
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[st+1]-hp[i].s))<0)st++;
			que[++ed] = i;
			if(hp[i].parallel(hp[que[ed-1]])) return false;
			p[ed]=hp[i].crosspoint(hp[que[ed-1]]);
		}
		
		while(st<ed && sgn( (hp[que[st]].e - hp[que[st]].s) ^(p[ed] - hp[que[st]].s)) < 0) ed--;
		while(st<ed && sgn( (hp[que[ed]].e - hp[que[ed]].s) ^ (p[st+1]-hp[que[ed]].s)) < 0) st++;
		if(st+1 >= ed)return false;
		return true;
	}
	
	//`得到最后半平面交得到的凸多边形`
	//`需要先调用halfplaneinsert() 且返回true`
	void getconvex(polygon &con) {
		p[st] = hp[que[st]].crosspoint(hp[que[ed]]);
		con.n = ed-st+1;
		for(int j = st,i = 0;j <= ed;i++,j++)
			con.p[i] = p[j];
	}
};

int n;
double r;
Point p[maxp];
Vector v[maxp], vt[maxp];

int main() {
	scanf("%d %lf", &n, &r);
	for(int i = 0;i < n; i++) p[i].input();
	reverse(p, p+n); p[n] = p[0];
	for(int i = 0;i < n; i++) {
		v[i] = Vector(p[i], p[i+1]);
		vt[i] = v[i].Normal();
	}
	
	halfplanes hf;
	hf.n = 0;
	for(int i = 0; i < n; i++) {
		Point t1 = p[i].add(vt[i].mul(r));
		Point t2 = t1.add(v[i]);
		hf.push(halfplane(t1, t2));
	}
	
	polygon res;
	hf.halfplaneinsert();
	hf.getconvex(res);
	
	double len = -1;
	Point a1, a2;
	for(int i = 0;i < res.n; i++) {
		for(int j = i+1;j < res.n; j++) {
			double now = dist(res.p[i], res.p[j]);
			if(now > len) {
				a1 = res.p[i];
				a2 = res.p[j];
				len = now;
			}
		}
	}
	
	printf("%.4f %.4f %.4f %.4f\n", a1.x, a1.y, a2.x, a2.y);
}