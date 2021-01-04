#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int _, n;

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
} p[1000006];

double qarea(double x1,double y1,double x2,double y2,double x3,double y3){
	return ((x2-x1)*(y3-y1)-(x3-x1)*(y2-y1))/2; //公式，求面积
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		
		double sumarea = 0, sumx = 0, sumy = 0;
		for(int i = 2;i < n; i++) {
			double area = fabs((p[i]-p[1])^(p[i+1]-p[1])) / 2;
			double x = (p[1].x + p[i].x + p[i+1].x);
			double y = (p[1].y + p[i].y + p[i+1].y);
			sumx += area * x;
			sumy += area * y;
			sumarea += area;
		}
		
		printf("%.2lf %.2lf\n", sumx/sumarea/3, sumy/sumarea/3);
	}
}