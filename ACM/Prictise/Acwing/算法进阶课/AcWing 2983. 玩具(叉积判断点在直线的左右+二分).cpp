#include <bits/stdc++.h>
using namespace std;

struct Point {
	double x, y;
	Point(){}
	Point(double _x,double _y) {
		x = _x; y = _y;
	}
	Point operator - (const Point &b) const {
		return Point(x - b.x,y - b.y);
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
};

int n, m, num[5003];
double x1, h1, x2, h2;
Line l[5003];
Point toy[5003];

double xmult(Point p0,Point p1,Point p2) {
	return (p1-p0)^(p2-p0);
}

bool ri(int mid, int pos) {
	// 直线AB A在B的上方 PA^PB > 0 P在直线的右边 等于0在线上 否则在左边
	if(xmult(toy[pos], l[mid].s, l[mid].e) > 0) return 1;
	return 0;
}

int main() {
	bool ok = 0;
	while (~scanf("%d", &n) && n) {
		scanf("%d %lf %lf %lf %lf", &m, &x1, &h1, &x2, &h2);
		if(ok) puts(""); ok = 1;
		l[1] = Line(Point(x1, h1), Point(x1, h2));
		for(int i = 2;i <= n+1; i++) {
			double w1, w2;
			scanf("%lf %lf", &w1, &w2);
			l[i] = Line(Point(w1, h1), Point(w2, h2));
		}
		
		memset(num, 0, sizeof(num));
		for(int i = 1;i <= m; i++) {
			scanf("%lf %lf", &toy[i].x, &toy[i].y);
			
			int l = 1, r = n+1, ans;
			while(l <= r) {
				int mid = (l+r) >> 1;
				if(ri(mid, i)) {
					ans = mid;
					l = mid+1;
				}
				else r = mid-1;
			}
			
			num[ans-1]++;
		}
		
		for(int i = 0;i <= n; i++) {
			printf("%d: %d\n", i, num[i]);
		}
	}
}