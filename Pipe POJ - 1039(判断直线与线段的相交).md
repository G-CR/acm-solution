## Pipe [POJ - 1039](https://vjudge.net/problem/POJ-1039/origin)

题意：给出n个点，还有另外n个点是前者的y值-1，构成了一个管道，问从管道左端射出一道光线，角度调整为最优光线最远可以达到多远。

思路：最优的情况就是上端和下段的顶点至少都经过一次可以产生最优。所以思路就是枚举上下所有的点组合，然后判断合法的且最远的那一组就可以了。

首先让上下端点相连接，然后把枚举的光线穿过这些线段，如果全部可以穿过，那么证明光线没有阻挡，可以从这头跑到那头去，然后就是不能全部穿过的情况，如果停留在这一组光线的左端，那么证明这道光线不是从入口处射入的，是不合法的，如果是在光线的右端点停止的，那么就可以计算交点算距离就可以了。

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define eps 1e-8

double sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
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
	
	// 判断直线相交的，无需要可以不用（如果相交返回交点的版本，下面有一个只做判断的版本）
	// 返回pair second为0重合 为1平行 为2相交且first为交点
	pair <int, Point> operator &(const Line &b)const { 
		Point res = s;
		if(sgn((s-e)^(b.s-b.e)) == 0) {
			if(sgn((b.s-s)^(b.e-s)) == 0)
				return make_pair(0,res);//两直线重合
			else return make_pair(1,res);//两直线平行
		}
		double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
		res.x += (e.x - s.x)*t;
		res.y += (e.y - s.y)*t;
		return make_pair(2,res);//有交点
	}
};

// 三个点计算叉积 p0p1 ^ p0p2
double xmult(Point p0,Point p1,Point p2) { 
	return (p1-p0)^(p2-p0);
}

// 判断直线l1和线段l2是否相交
bool Seg_inter_line(Line l1, Line l2) { 
	return sgn(xmult(l2.s,l1.s,l1.e))*sgn(xmult(l2.e,l1.s,l1.e)) <= 0;
}

int n;
Point high[50], low[50];

int check_cross(Line wtf) {
	for(int i = 0;i < n; i++) {
		Line now = Line(high[i], low[i]);
		if(!Seg_inter_line(wtf, now)) return i;
	}
	return -1;
}

int main() {
	while(~scanf("%d", &n) && n) {
		for(int i = 0;i < n; i++) {
			scanf("%lf %lf", &high[i].x, &high[i].y);
			low[i] = high[i];
			low[i].y -= 1.0;
		}
		
		bool all = 0;
		double ans = -1000000000.0;
		for(int i = 0;i < n; i++) {
			for(int j = 0;j < n; j++) {
				Line now = Line(high[i], low[j]);
				int pos = check_cross(now);
				if(pos == -1) { all = 1; break;}
				if(pos <= max(i, j)) continue;
				
				if(Seg_inter_line(now, Line(high[pos-1], high[pos]))) {
					Point res = (now & Line(high[pos-1], high[pos])).second;
					ans = max(ans, res.x);
				}
				if(Seg_inter_line(now, Line(low[pos-1], low[pos]))) {
					Point res = (now & Line(low[pos-1], low[pos])).second;
					ans = max(ans, res.x);
				}
			}
			if(all) break;
		}
		
		if(all) puts("Through all the pipe.");
		else printf("%.2lf\n", ans);
	}
}
```

