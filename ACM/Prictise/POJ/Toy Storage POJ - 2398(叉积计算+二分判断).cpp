#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, m, x, y, x2, y2, a, b;
int num[5005], ans[5005];

struct Point {
	int x,y;
	Point(){}
	Point(int _x,int _y) {
		x = _x; y = _y;
	}
	Point operator + (const Point& b) const {
		return Point(x + b.x,y + b.y);
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

bool cmp(Line a, Line b) {
	return a.s.x < b.s.x;
}


int main() {
	while(~scanf("%d", &n) && n) {
		memset(num, 0, sizeof num);
		memset(ans, 0, sizeof ans);
		scanf("%d %d %d %d %d", &m, &x, &y, &x2, &y2);
		for(int i = 0;i < n; i++) {
			scanf("%d %d", &a, &b);
			line[i] = Line(Point(a, y), Point(b, y2));
		}
		line[n] = Line(Point(x2, y), Point(x2, y2));
		sort(line, line+n, cmp);
		
		while(m--) {
			scanf("%d %d", &a, &b);
			Point p = Point(a, b);
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
			
			num[res]++;
		}
		
		for(int i = 0;i <= n; i++) {
//			printf("%d: %d\n", i, num[i]);
			if(num[i]) ans[num[i]]++;
		}
		puts("Box");
		for(int i = 1;i <= n; i++) {
			if(ans[i]) {
				printf("%d: %d\n", i, ans[i]);
			}
		}
	}
}