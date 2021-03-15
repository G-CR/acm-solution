[题目链接](https://vjudge.net/problem/POJ-1271)

**题意：** 用一个凸 **n** 边形的面包选择其中的 **k** 条边去蘸一个装在无限大的杯子里高 **h** 的牛奶，面包边保持与杯子底部平面的状态，问怎么选择这 k 条边使得蘸到牛奶的面积最大。

**思路：** 

1、不好直接求蘸得牛奶区域的面积，所以可以选择求没有蘸到牛奶的面积。求出整个面包的面积，再减去没有蘸到牛奶的面积就可以了。

2、把每一条边的单位法向量求出来，然后乘以 h 就可以得到实际向内平移的法向量，再加上原本的向量就可以得到蘸得牛奶和没蘸得牛奶的边界线。

3、用模拟退火来选出需要蘸的 k 条边，保证这 k 条边是可以使得面积最大。

4、选出来后 用原来的n条边加上后来的k条边 算出一个半平面交就是最终的最小没有蘸到的面包面积。

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;

const double eps = 1e-8;
const int maxp = 1000;

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
	Point mul(double b) {
		return Point(x*b, y*b);
	}
	Point operator + (const Point &b) const {
		return Point(x+b.x, y+b.y); 
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
	double getarea() {
		double sum = 0;
		for(int i = 0;i < n;i++){
			sum += (p[i]^p[(i+1)%n]);
		}
		return fabs(sum)/2;
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

struct node {
	int id;
	double len;
} g[maxp];

bool cmp(node a, node b) {
	return a.len > b.len;
}

double ans;
int n, k, h;
Point p[maxp];
Line tl[maxp];
polygon poly;
Vector v[maxp], vt[maxp];
halfplanes hf;

void sa() {
	double T = 100, D = 0.915;
	double cur = 1e9;
	while(T > 1e-14) {
		int pos1 = rand() % n;
		int pos2 = rand() % n;
		if(pos1 == pos2) continue;
		swap(g[pos1], g[pos2]);
		
		hf.n = 0;
		for(int i = 0; i < n; i++) hf.push(poly.l[i]);
		for(int i = 0; i < k; i++) hf.push(tl[g[i].id]);
		
		bool ok = hf.halfplaneinsert();
		
		double now;
		if(!ok) now = 0;
		else {
			polygon res;
			hf.getconvex(res);
			now = res.getarea();
		}
		
		if(now < cur) {
			cur = now;
			if(ans > cur) ans = cur;
		}
		else if(exp(ans-now)/T*RAND_MAX > rand()) {
			cur = now;
		}
		else swap(g[pos1], g[pos2]);
		
		T *= D;
	}
	
}

void solve() {
	int num = 20;
	while(num--) {
		sa();
	}
}

int main() {
	// srand(time(NULL)); time函数在 POJ 会报错 runtime error
	while(~scanf("%d %d %d", &n, &k, &h) && n) {
		ans = 1e9;
		poly.input(n);
		poly.getline();
		double s = poly.getarea();
		
		for(int i = 0; i < n; i++) {
			v[i] = Vector(poly.l[i]);
			vt[i] = v[i].Normal();
			g[i] = {i, v[i].length()};
		}
		
		for(int i = 0; i < n; i++) {
			Point p1 = poly.p[i] + vt[i].mul(h);
			Point p2 = p1 + v[i];
			tl[i] = Line(p1, p2);
		}
		
		sort(g, g+n, cmp);
		
		solve();
		
		printf("%.2f\n", s-ans);
	}
}
```

