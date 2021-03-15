#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const int maxp = 103;
const double eps = 1e-8;

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point {
	double x,y;
	Point(){}
	Point(double _x,double _y){
		x = _x;
		y = _y;
	}
	void input() {//输入
		scanf("%lf%lf", &x, &y);
	}
	bool operator == (Point b)const{
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	Point operator -(const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	//叉积
	double operator ^(const Point &b)const{
		return x*b.y - y*b.x;
	}
};

struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;
		e = _e;
	}
	Line(double a,double b,double c){//ax+by+c=0
		if(!sgn(a)){
			s=Point(0,-c/b),e=Point(1,-c/b);
			if(sgn(b)>0)adjust();   // 保证点是逆时针 有时候需要变号
		}
		else if(!sgn(b)){
			s=Point(-c/a,0),e=Point(-c/a,1);
			if(sgn(a)<0)adjust();
		}
		else{
			s=Point(0,-c/b),e=Point(1,(-c-a)/b);
			if(sgn(b)>0)adjust();
		}
	}
	void adjust(){swap(s,e);}
	
	bool operator ==(Line v) {
		return (s == v.s)&&(e == v.e);
	}
	
	//`两向量平行(对应直线平行或重合)`
	bool parallel(Line v){
		return sgn((e-s)^(v.e-v.s)) == 0;
	}
	//`求两直线的交点`
	//`要保证两直线不平行或重合`
	Point crosspoint(Line v){
		double a1 = (v.e-v.s)^(s-v.s);
		double a2 = (v.e-v.s)^(e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1),(s.y*a2-e.y*a1)/(a2-a1));
	}
};

struct polygon {
	int n;
	Point p[maxp];
	Line l[maxp];
	void input(int _n) {
		n = _n;
		for (int i = 0; i < n; i++)
			p[i].input();
	}
	
	void getline() {//通过顶点得到线段
		for (int i = 0; i < n; i++)
			l[i] = Line(p[i], p[(i + 1) % n]);
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
		
		while(st<ed && sgn((hp[que[st]].e-hp[que[st]].s)^(p[ed]-hp[que[st]].s))<0)ed--;
		while(st<ed && sgn((hp[que[ed]].e-hp[que[ed]].s)^(p[st+1]-hp[que[ed]].s))<0)st++;
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
double v[maxp], u[maxp], w[maxp];
polygon P;
halfplanes hf;

int main() {
	scanf("%d", &n);
	for(int i = 0;i < n; i++) scanf("%lf %lf %lf", &v[i], &u[i], &w[i]);
	for(int i = 0; i < n; i++) {
		bool ok = 1;
		hf.n = 0;
		for(int j = 0; j < n; j++) {
			if(i == j) continue;
			if(v[i] <= v[j] && u[i] <= u[j] && w[i] <= w[j]) {
				ok = 0;
				break;
			}
			
			double a = (v[j] - v[i]) / (v[i] * v[j]);
			double b = (u[j] - u[i]) / (u[i] * u[j]);
			double c = (w[j] - w[i]) / (w[i] * w[j]);
			
			hf.push(halfplane(Line(a, b, c)));
		}
		
		if(ok) {
			hf.push(halfplane(Point(0,0), Point(100000, 0)));
			hf.push(halfplane(Point(100000, 0), Point(100000,100000)));
			hf.push(halfplane(Point(100000, 100000), Point(0, 100000)));
			hf.push(halfplane(Point(0, 100000), Point(0, 0)));
			ok = hf.halfplaneinsert();
		}
		
		if(ok) puts("Yes");
		else puts("No");
	}
}