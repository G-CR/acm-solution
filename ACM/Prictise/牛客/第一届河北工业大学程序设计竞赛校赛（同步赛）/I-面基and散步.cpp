#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);

int sgn(double x){
	if(fabs(x) < eps)return 0;
	if(x < 0)return -1;
	else return 1;
}
struct Point{
	double x,y;
	Point(){}
	Point(double _x,double _y){
		x = _x;
		y = _y;
	}
	void input(){
		scanf("%lf%lf",&x,&y);
	}
	
	Point operator -(const Point &b)const{
		return Point(x-b.x,y-b.y);
	}
	//叉积
	double operator ^(const Point &b)const{
		return x*b.y - y*b.x;
	}
	//点积
	double operator *(const Point &b)const{
		return x*b.x + y*b.y;
	}
	//返回长度
	double len(){
		return hypot(x,y);//库函数
	}
	//返回两点的距离
	double distance(Point p){
		return hypot(x-p.x,y-p.y);
	}
	Point operator +(const Point &b)const{
		return Point(x+b.x,y+b.y);
	}
	Point operator *(const double &k)const{
		return Point(x*k,y*k);
	}
	Point operator /(const double &k)const{
		return Point(x/k,y/k);
	}
	//`计算pa  和  pb 的夹角`
	//`就是求这个点看a,b 所成的夹角`
	//`测试 LightOJ1203`
	double rad(Point a,Point b){
		Point p = *this;
		return fabs(atan2( fabs((a-p)^(b-p)),(a-p)*(b-p) ));
	}
	//`化为长度为r的向量`
	Point trunc(double r){
		double l = len();
		if(!sgn(l))return *this;
		r /= l;
		return Point(x*r,y*r);
	}
	//`逆时针旋转90度`
	Point rotleft(){
		return Point(-y,x);
	}
	//`顺时针旋转90度`
	Point rotright(){
		return Point(y,-x);
	}
};

double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

struct Line{
	Point s,e;
	Line(){}
	Line(Point _s,Point _e){
		s = _s;
		e = _e;
	}
	//求线段长度
	double length(){
		return s.distance(e);
	}
	//点到直线的距离
	double dispointtoline(Point p){
		return fabs((p-s)^(e-s))/length();
	}
	//点到线段的距离
	double dispointtoseg(Point p){
		if(sgn((p-s)*(e-s))<0 || sgn((p-e)*(s-e))<0)
			return min(p.distance(s),p.distance(e));
		return dispointtoline(p);
	}
};

// 圆相关
struct circle{
	Point p;//圆心
	double r;//半径
	circle(){}
	circle(Point _p,double _r){
		p = _p;
		r = _r;
	}
	circle(double x,double y,double _r){
		p = Point(x,y);
		r = _r;
	}
	void input(){
		p.input();
		scanf("%lf",&r);
	}
	int relation(Point b){
		double dst = b.distance(p);
		if(sgn(dst-r) < 0)return 2;
		else if(sgn(dst-r)==0)return 1;
		return 0;
	}
	
	int relationseg(Line v){
		double dst = v.dispointtoseg(p);
		if(sgn(dst-r) < 0)return 2;
		else if(sgn(dst-r) == 0)return 1;
		return 0;
	}
	
	//`过一点作圆的切线(先判断点和圆的关系)`
	//`测试：UVA12304`
	int tangentline(Point q,Line &u,Line &v){
		int x = relation(q);
		if(x == 2)return 0;
		if(x == 1){
			u = Line(q,q + (q-p).rotleft());
			v = u;
			return 1;
		}
		double d = p.distance(q);
		double l = r*r/d;
		double h = sqrt(r*r-l*l);
		u = Line(q,p + ((q-p).trunc(l) + (q-p).rotleft().trunc(h)));
		v = Line(q,p + ((q-p).trunc(l) + (q-p).rotright().trunc(h)));
		return 2;
	}
};



circle c;
Point a, b;

double cal(Point k) {
	Line u, v;
	c.tangentline(k, u, v);
	Point p = u.e;
	double tr = fabs((k - c.p) ^ (p - c.p)) / 2;
	double ag = c.p.rad(k, p);
	return tr - ag * (PI * c.r * c.r) / (2*PI);
}

int main() {
	c.input();
	a.input(); b.input();
	Line l (a, b);
	double ans = 0;
	if(c.relationseg(l) <= 1) {
		double sc = PI * c.r * c.r;
		double ans = sc + fabs((a-c.p) ^ (b-c.p)) / 2;
		double ag = c.p.rad(a, b);
		ans -= ag * sc / (2*PI);
		printf("%.4f\n", ans);
	}
	else {
		ans += cal(a) + cal(b);
		ans += PI * c.r * c.r;
		printf("%.4f\n", ans);
	}
}