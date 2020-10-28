## Intersection [POJ - 1410](https://vjudge.net/problem/POJ-1410/origin)

题意：给一个矩形，再给一条线段。问是否存在公共点或者线段在矩形的内部

思路：判断是否在内部就用坐标判断大小就可以了，如果线段的横坐标在矩形横坐标之间，并且纵坐标在矩形纵坐标之间，那么就在内部。相交就把矩形的四条边处理出来，然后判断相交就好了。

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-8
using namespace std;

double sgn(double x) {
	if(fabs(x) < eps)return 0;
	if(x < 0) return -1;
	return 1;
}

struct Point { // 表示点
	double x, y;
	Point(){}
	Point(double _x,double _y) {
		x = _x; y = _y;
	}
	Point operator + (const Point& b) const {
		return Point(x + b.x,y + b.y);
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x,y - b.y);
	}
	double operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
	double operator ^ (const Point &b) const {
		return x*b.y - y*b.x;
	}
};

struct Line { // 表示线段
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
	
	//线段与线段相交判断
	//2 规范相交
	//1 非规范相交
	//0 不相交
	int seg_cross_seg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		int d3 = sgn((v.e-v.s)^(s-v.s));
		int d4 = sgn((v.e-v.s)^(e-v.s));
		if((d1^d2)==-2&&(d3^d4)==-2) return 2;
		return (d1==0 &&sgn((v.s-s)*(v.s-e))<=0)||
				(d2==0 &&sgn((v.e-s)*(v.e-e))<=0)||
				(d3==0 &&sgn((s-v.s)*(s-v.e))<=0)||
				(d4==0 &&sgn((e-v.s)*(e-v.e))<=0);
	}
};


int _;
double lx[2], ly[2];
double sqx[2], sqy[2];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lf %lf %lf %lf", &lx[0], &ly[0], &lx[1], &ly[1]);
		scanf("%lf %lf %lf %lf", &sqx[0], &sqy[0], &sqx[1], &sqy[1]);
		if(sqx[0] > sqx[1]) swap(sqx[0], sqx[1]);
		if(sqy[0] > sqy[1]) swap(sqy[0], sqy[1]);
		
		Line npy = Line(Point(lx[0], ly[0]), Point(lx[1], ly[1]));
		Line sqr[4];
		sqr[0] = Line(Point(sqx[0], sqy[0]), Point(sqx[1], sqy[0]));
		sqr[1] = Line(Point(sqx[1], sqy[0]), Point(sqx[1], sqy[1]));
		sqr[2] = Line(Point(sqx[1], sqy[1]), Point(sqx[0], sqy[1]));
		sqr[3] = Line(Point(sqx[0], sqy[1]), Point(sqx[0], sqy[0]));
		
		bool ok = 0;
		
		if(lx[0] > lx[1]) swap(lx[0], lx[1]);
		if(ly[0] > ly[1]) swap(ly[0], ly[1]);
		
		if(lx[0] > sqx[0] && lx[1] < sqx[1] && ly[0] > sqy[0] && ly[1] < sqy[1]) ok = 1;
		
		for(int i = 0;i < 4; i++) {
			if(sqr[i].seg_cross_seg(npy) != 0) {
				ok = 1; break;
			}
		}
		
		if(ok) puts("T");
		else puts("F");
	}
}
```

