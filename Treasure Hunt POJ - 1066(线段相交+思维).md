## Treasure Hunt [POJ - 1066 ](https://vjudge.net/problem/POJ-1066/origin)

题意：在一个框里面，有很多互相交错的线段，问从外面开始往里走，碰到一次线段答案+1，问答案最少是多少就能到达目的地，需要从线段的中点进入。

思路：其实把外围的中点坐标处理出来，然后枚举外围点与目的地连线，穿过的线段数与答案取min就可以了，用这个方法与从中点过其实也没有冲突的，也并不会产生谁更优的策略。

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
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
	Point(double _x, double _y) {
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

} l[33];

int num;
int ecnt = 0, scnt = 0, wcnt = 0, ncnt = 0;
double x[2], y[2], baox, baoy;
double e[33], s[33], w[33], n[33];

void tian(int i) {
	if(x[i] == 0) w[wcnt++] = y[i];
	if(y[i] == 0) s[scnt++] = x[i];
	if(x[i] == 100) e[ecnt++] = y[i];
	if(y[i] == 100) n[ncnt++] = x[i];
}

bool cmp(double a, double b) {
	return a < b;
}

int main() {
	scanf("%d", &num);
	ecnt = 0, scnt = 0, wcnt = 0, ncnt = 0;
	for(int i = 0;i < num; i++) {
		scanf("%lf %lf %lf %lf", &x[0], &y[0], &x[1], &y[1]);
		l[i] = Line(Point(x[0], y[0]), Point(x[1], y[1]));
		tian(0); tian(1);
	}
	scanf("%lf %lf", &baox, &baoy);
	
	e[ecnt++] = 0; e[ecnt++] = 100;
	s[scnt++] = 0; s[scnt++] = 100;
	w[wcnt++] = 0; w[wcnt++] = 100;
	n[ncnt++] = 0; n[ncnt++] = 100;
	sort(e, e+ecnt); sort(s, s+scnt); sort(w, w+wcnt); sort(n, n+ncnt);
	
//	for(int i = 0;i < ecnt; i++) printf("%.2lf ", e[i]); puts("");
//	for(int i = 0;i < scnt; i++) printf("%.2lf ", s[i]); puts("");
//	for(int i = 0;i < wcnt; i++) printf("%.2lf ", w[i]); puts("");
//	for(int i = 0;i < ncnt; i++) printf("%.2lf ", n[i]); puts("");
	
	Point p[200]; int pcnt = 0;
	for(int i = 0;i < ecnt-1; i++) p[pcnt++] = Point(100, (e[i]+e[i+1])/2);
	for(int i = 0;i < scnt-1; i++) p[pcnt++] = Point((s[i]+s[i+1])/2, 0);
	for(int i = 0;i < wcnt-1; i++) p[pcnt++] = Point(0, (w[i]+w[i+1])/2);
	for(int i = 0;i < ncnt-1; i++) p[pcnt++] = Point((n[i]+n[i+1])/2, 100);
	
//	for(int i = 0;i < pcnt; i++) {
//		printf("%.2lf %.2lf\n", p[i].x, p[i].y);
//	}
	
	int ans = 1e9;
	for(int i = 0;i < pcnt; i++) {
		int now = 0;
		Line t = Line(Point(baox, baoy), p[i]);
		for(int j = 0;j < num; j++) {
			if(t.seg_cross_seg(l[j]) == 2) now++;
		}
		ans = min(ans, now);
//		printf("%.2lf %.2lf\n", p[i].x, p[i].y);
//		printf("now = %d\n\n", now);
	}
	
	printf("Number of doors = %d\n", ans+1);
}
```

