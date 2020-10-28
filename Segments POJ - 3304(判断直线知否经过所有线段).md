## Segments [POJ - 3304](https://vjudge.net/problem/POJ-3304/origin)

题意：给n个线段的端点，问你将这些线段都投影到同一条直线上是否所有的线段都有交点。

思路：如果可以有一条直线可以穿过所有的线段的话那么就存在题意中的直线。

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-8
using namespace std;

int _, n;

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
} p[300];

struct Line { // 表示线段
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
} line[200];

double xmult(Point p0,Point p1,Point p2) { // 三个点计算叉积 p0p1 ^ p0p2
	return (p1-p0)^(p2-p0);
}

int sgn(double x) {
	if(fabs(x) < eps)return 0;
	if(x < 0) return -1;
	return 1;
}

bool Seg_inter_line(Line l1,Line l2) { //判断直线l1和线段l2是否相交 
	return sgn(xmult(l2.s,l1.s,l1.e))*sgn(xmult(l2.e,l1.s,l1.e)) <= 0;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		double x, y, x2, y2;
		int cnt = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%lf %lf %lf %lf", &x, &y, &x2, &y2);
			p[++cnt] = Point(x, y);
			p[++cnt] = Point(x2, y2);
			line[i] = Line(p[cnt-1], p[cnt]);
		}
		
		bool ans = 0;
		for(int i = 1;i <= cnt; i++) {
			for(int j = i+1;j <= cnt; j++) {
				if(p[i].x == p[j].x && p[i].y == p[j].y) continue;
				Line l = Line(p[i], p[j]);
				bool ok = 1;
				for(int k = 1;k <= n; k++) {
					if(!Seg_inter_line(l, line[k])) {
						ok = 0; break;
					}
				}
				if(ok) {
//					printf("%lf %lf %lf %lf\n", p[i].x, p[i].y, p[j].x, p[j].y);
					ans = 1;
					break;
				}
			}
			if(ans) break;
		}
		
		if(ans) puts("Yes!");
		else puts("No!");
	}
}
```

