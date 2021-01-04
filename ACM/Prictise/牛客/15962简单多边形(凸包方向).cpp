#include <bits/stdc++.h>
using namespace std;
const double eps = 1e-4;

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
	
	bool getdir() {
		double sum = 0;
		for(int i = 0;i < n; i++) {
			sum += (p[i] ^ p[(i+1)%n]);
		}
		if(sgn(sum) > 0) return 1;
		return 0;
	}
};



int main() {
	int n;
	scanf("%d", &n);
	polygon poly;
	poly.input(n);
	puts(poly.getdir()==1?"counterclockwise":"clockwise");
}