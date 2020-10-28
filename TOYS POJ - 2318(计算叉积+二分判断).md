## TOYS [POJ - 2318](https://vjudge.net/problem/POJ-2318/origin)

题意：从左往右依次给出不相交的n个线段放入一个矩形，将举行分成n+1份，再给出m个玩具的坐标，问每个区域玩具的个数

思路：有一个思路很好想到，就是枚举每一个玩具，然后对于当前玩具枚举每一条线段，用叉积的方法判断玩具是在线段的左边还是右边。然后用一个数组记录答案就可以了，但是这样不出意外是会超时的。可以注意到给出的线段没有相交，并且坐标也是由小到大给的，所以具有单调性，就可以把第二层枚举变为二分来做 $n^2$ 就变成 $nlogn$ 了

```cpp
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int n, m, x, y, x2, y2, a, b, ans[5005];

struct Point {
	int x,y;
	Point(){}
	Point(int _x,int _y) {
		x = _x; y = _y;
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x,y - b.y);
	}
	int operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
	int operator ^ (const Point &b) const {
		return x*b.y - y*b.x;
	}
};

struct Line {
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
} line[5005];

int xmult(Point p0,Point p1,Point p2) { 
	return (p1-p0)^(p2-p0);
}


int main() {
	while(~scanf("%d", &n) && n) {
		memset(ans, 0, sizeof ans);
		scanf("%d %d %d %d %d", &m, &x, &y, &x2, &y2);
				
		for(int i = 0;i < n; i++) {
			scanf("%d %d", &a, &b);
			line[i] = Line(Point(a, y), Point(b, y2));
		}
		
		line[n] = Line(Point(x2, y), Point(x2, y2));
		
		for(int i = 1;i <= m; i++) {
			Point p; int px, py;
			scanf("%d %d", &px, &py);
			p = Point(px, py);
			int l = 0, r = n, res = 0;
			
			while(l <= r) {
				int mid = (l + r) >> 1;
				if(xmult(p, line[mid].s, line[mid].e) < 0) {
					res = mid;
					r = mid-1;
				}
				else {
					l = mid+1;
				}
			}
			ans[res]++;
		}
		
		for(int i = 0; i <= n; i++) {
			printf("%d: %d\n", i, ans[i]);
		}
		puts("");
	}
}
```



还有个一模一样题目

## Toy Storage POJ - 2398

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

