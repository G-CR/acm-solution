#include <bits/stdc++.h>
using namespace std;

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

// 多边形面积(点坐标顺时针给出,逆时针为负数)
double PolygonArea(Point *p,int n) {
	double area=0;
	for(int i = 1;i < n-1; i++)
		area += (p[i]-p[0])^(p[i+1]-p[0]);
	return area/2;
}

int n;

int main() {
	Point p[10];
	scanf("%d", &n);
	for(int i = 0;i < n; i++) {
		scanf("%lf %lf", &p[i].x, &p[i].y);
	}
	
	printf("%d\n", int(PolygonArea(p, n)+0.5));
}
