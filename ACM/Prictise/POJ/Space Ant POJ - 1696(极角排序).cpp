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
	int id;
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
} p[100];

int _, n, pos;
double dist(Point a, Point b) {
	return sqrt((a-b)*(a-b));
}
bool cmp(Point a,Point b) { // 极角排序
	double tmp = (a-p[pos])^(b-p[pos]);
	// 找到与当前点逆时针极角最小的点 把 '<' 改成 '>' 就是找极角最大的点
	if(sgn(tmp) == 0)
		return dist(p[pos],a) < dist(p[pos],b);
	else if(sgn(tmp) < 0)return false;
	else return true;
}


int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 0;i < n; i++) {
			scanf("%d %lf %lf", &p[i].id, &p[i].x, &p[i].y);
			if(p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x)) {
				swap(p[i], p[0]);
			}
		}
		
		pos = 0;
		for(int i = 1;i < n; i++) {
			sort(p+i, p+n, cmp);
			pos++;
		}
		
		printf("%d ", n);
		for(int i = 0;i < n; i++) {
			printf("%d ", p[i].id);
		} puts("");
	}
}