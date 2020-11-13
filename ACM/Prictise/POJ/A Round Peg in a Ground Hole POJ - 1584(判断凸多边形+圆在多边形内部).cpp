#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <math.h>

using namespace std;

const double eps = 1e-8;
const double PI = acos(-1.0);
int sgn(double x) {
	if(fabs(x) < eps)return 0;
	if(x < 0)return -1;
	else return 1;
}

struct Point {
	double x,y;
	Point(){}
	Point(double _x,double _y) {
		x = _x;y = _y;
	}
	Point operator -(const Point &b)const {
		return Point(x - b.x,y - b.y);
	}
	//叉积
	double operator ^(const Point &b)const {
		return x*b.y - y*b.x;
	}
	//点积
	double operator *(const Point &b)const {
		return x*b.x + y*b.y;
	}
};
struct Line {
	Point s,e;
	Line(){}
	Line(Point _s,Point _e)
	{
		s = _s;e = _e;
	}
};
//*两点间距离
double dist(Point a,Point b) {
	return sqrt((a-b)*(a-b));
}

//判断凸多边形
//允许共线边
//点可以是顺时针给出也可以是逆时针给出
//点的编号1~n-1
bool isconvex(Point poly[],int n) {
	bool s[3];
	memset(s,false,sizeof(s));
	for(int i = 0;i < n;i++) {
		s[sgn( (poly[(i+1)%n]-poly[i])^(poly[(i+2)%n]-poly[i]) )+1] = true;
		if(s[0] && s[2])return false;
	}
	return true;
}

//点到线段的距离
//返回点到线段最近的点
Point NearestPointToLineSeg(Point P,Line L) {
	Point result;
	double t = ((P-L.s)*(L.e-L.s))/((L.e-L.s)*(L.e-L.s));
	if(t >= 0 && t <= 1) {
		result.x = L.s.x + (L.e.x - L.s.x)*t;
		result.y = L.s.y + (L.e.y - L.s.y)*t;
	}
	else {
		if(dist(P,L.s) < dist(P,L.e))
			result = L.s;
		else result = L.e;
	}
	return result;
}
//*判断点在线段上
bool OnSeg(Point P,Line L) {
	return
	sgn((L.s-P)^(L.e-P)) == 0 &&
	sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
	sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

//*判断线段相交
bool inter(Line l1,Line l2) {
	return
	max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
	max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
	max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
	max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
	sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
	sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

//*判断点在任意多边形内
//射线法，poly[]的顶点数要大于等于3,点的编号0~n-1
//返回值
//-1:点在凸多边形外
//0:点在凸多边形边界上
//1:点在凸多边形内
int inPoly(Point p,Point poly[],int n) {
	int cnt;
	Line ray,side;
	cnt = 0;
	ray.s = p;
	ray.e.y = p.y;
	ray.e.x = -100000000000.0;//-INF,注意取值防止越界

	for(int i = 0;i < n;i++) { 
		side.s = poly[i];
		side.e = poly[(i+1)%n];

		if(OnSeg(p,side)) return 0;

		//如果平行轴则不考虑
		if(sgn(side.s.y - side.e.y) == 0)
			continue;

		if(OnSeg(side.s,ray)) {
			if(sgn(side.s.y - side.e.y) > 0)cnt++;
		}
		else if(OnSeg(side.e,ray)) {
			if(sgn(side.e.y - side.s.y) > 0)cnt++;
		}
		else if(inter(ray,side)) cnt++;
	}
	if(cnt % 2 == 1) return 1;
	else return -1;
}

int n;
double R;
Point p[110], circle;

int main() {
	while(scanf("%d", &n) && n != 1) {
		scanf("%lf %lf %lf", &R, &circle.x, &circle.y);
		for(int i = 0;i < n; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		if(!isconvex(p, n)) {
			puts("HOLE IS ILL-FORMED");
			continue;
		}
		if(inPoly(circle, p, n) < 0) {
			puts("PEG WILL NOT FIT");
			continue;
		}
		bool ok = 1;
		for(int i = 0;i < n; i++) {
			Line now = Line(p[i], p[(i+1)%n]);
			Point t = NearestPointToLineSeg(circle, now);
			if(dist(t, circle) < R) {ok = 0; break;}
		}
		if(ok) puts("PEG WILL FIT");
		else puts("PEG WILL NOT FIT");
	}
}