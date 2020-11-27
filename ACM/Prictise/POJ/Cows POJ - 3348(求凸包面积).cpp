#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
const double eps = 1e-8;

int sgn(double x) {
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
	bool operator < (Point b) const {
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0: x < b.x;
	}
	bool operator == (Point b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
};

//两点距离
double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

const int maxp = 1e3+3;
struct polygon {
	int n;
	Point p[maxp];
	void input(int _n) {
		n = _n;
		for(int i = 0;i < n; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
	}
	
	struct cmp {
		Point p;
		cmp(const Point &p0) {p = p0;}
		bool operator() (const Point &aa, const Point &bb) {
			Point a = aa, b = bb;
			int d = sgn((a-p)^(b-p));
			if(d == 0) {
				return sgn(dist(a,p)-dist(b,p)) < 0;
			}
			return d > 0;
		}
	};
	
	// 进行极角排序
	// 首先需要找到最左下角的点
	// 首先重载好 Point 的 < 操作符 (min函数要用)
	void norm() {
		Point mi = p[0];
		for(int i = 1;i < n; i++) mi = min(mi, p[i]);
		sort(p, p+n, cmp(mi));
	}
	
	// 得到凸包
	// 得到的凸包里面的点编号是 0～n-1
	void Graham(polygon &convex) {
		norm();
		int &top = convex.n;
		top = 0;
		if(n == 1) {
			top = 1;
			convex.p[0] = p[0];
			return;
		}
		if(n == 2) {
			top = 2;
			convex.p[0] = p[0];
			convex.p[1] = p[1];
			if(convex.p[0] == convex.p[1]) top--;
			return;
		}
		
		convex.p[0] = p[0];
		convex.p[1] = p[1];
		top = 2;
		for(int i = 2;i < n; i++) {
			// 如果一条边上有许多点都有用的话把 <= 改成 <
			while(top > 1 && sgn((convex.p[top-1]-convex.p[top-2]) ^ (p[i]-convex.p[top-2])) <= 0) 
				top--;
			convex.p[top++] = p[i];
		}
		if(convex.n == 2 && (convex.p[0] == convex.p[1])) convex.n--;
	}
	
	// 凸包面积
	double getarea() {
		double sum = 0;
		for(int i = 0;i < n; i++) {
			sum += (p[i] ^ p[(i+1)%n]);
		}
		return fabs(sum) / 2;
	}
};

int n;
polygon poly, convex;

int main() {
	scanf("%d", &n);
	poly.input(n);
	poly.Graham(convex);
	printf("%d\n", (int)(convex.getarea()/50));
}