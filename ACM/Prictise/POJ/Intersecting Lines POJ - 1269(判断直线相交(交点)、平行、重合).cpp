#include <iostream>
#include <cstdio>
#include <cmath>
#define eps 1e-8
using namespace std;

int _;

int sgn(double x) {
	if(fabs(x) < eps)return 0;
	if(x < 0) return -1;
	return 1;
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
} p[4];

struct Line { // 表示线段
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
	
	// 判断直线相交的，无需要可以不用
	// 返回pair second为0重合 为1平行 为2相交且first为交点
	pair <Point,int> operator &(const Line &b)const { 
		Point res = s;
		if(sgn((s-e)^(b.s-b.e)) == 0) {
			if(sgn((b.s-s)^(b.e-s)) == 0)
				return make_pair(res,0);//两直线重合
			else return make_pair(res,1);//两直线平行
		}
		double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
		res.x += (e.x - s.x)*t;
		res.y += (e.y - s.y)*t;
		return make_pair(res,2);//有交点
	}
};

int main() {
	scanf("%d", &_);
	puts("INTERSECTING LINES OUTPUT");
	while(_--) {
		for(int i = 0;i < 4; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		Line l[2];
		l[0] = Line(p[0], p[1]);
		l[1] = Line(p[2], p[3]);
		
		pair <Point, int> ans = l[0] & l[1];
		if(ans.second == 0) puts("LINE");
		else if(ans.second == 1) puts("NONE");
		else {
			printf("POINT %.2f %.2f\n", ans.first.x, ans.first.y);
		}
	}
	puts("END OF OUTPUT");
}