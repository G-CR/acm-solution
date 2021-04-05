#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-8;
const double inf = 1e20;
const double pi = acos(-1.0);

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
	bool operator == (Point b)const{
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
	bool operator < (Point b)const{
		return sgn(x-b.x)== 0?sgn(y-b.y)<0:x<b.x;
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
	//返回长度的平方
	double len2(){
		return x*x + y*y;
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
};


struct circle {
	Point p;
	double r;
	circle(){}
	circle(Point _p,double _r){
		p = _p;
		r = _r;
	}
	circle(double x,double y,double _r){
		p = Point(x,y);
		r = _r;
	}
};

int n;
Point cen, s, t;
Point p[20];

int main() {
	int cas = 0;
	while(1) {
		cen.input(); s.input(); t.input();
		if(cen == Point(0,0) && s == Point(0,0) && t == Point(0,0)) break;
		
		scanf("%d", &n);
		p[0] = s; p[n+1] = t;
		for(int i = 1; i <= n; i++) {
			p[i].input();
		}
		
		circle c (cen, cen.distance(s));
		double angle = cen.rad(s, t);
		
		double len1 = (2 * pi * c.r) * (angle / (2*pi));
		double len2 = 0;
		for(int i = 1; i <= n+1; i++) {
			len2 += p[i].distance(p[i-1]);
		}
		
		printf("Case #%d: ", ++cas);
		if(len1 > len2) {
			puts("Watch out for squirrels!\n");
		}
		else puts("Stick to the Circle.\n");
	}
}