#include <iostream>
#include <cstdio>
#include <cmath>
#include <queue>
#define eps 1e-8
using namespace std;


double sgn(double x) {
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
};

struct Line { // 表示线段
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
	
	//线段与线段相交判断
	//2 规范相交
	//1 非规范相交
	//0 不相交
	int seg_cross_seg(Line v){
		int d1 = sgn((e-s)^(v.s-s));
		int d2 = sgn((e-s)^(v.e-s));
		int d3 = sgn((v.e-v.s)^(s-v.s));
		int d4 = sgn((v.e-v.s)^(e-v.s));
		if((d1^d2)==-2&&(d3^d4)==-2) return 2;
		return (d1==0 &&sgn((v.s-s)*(v.s-e))<=0)||
				(d2==0 &&sgn((v.e-s)*(v.e-e))<=0)||
				(d3==0 &&sgn((s-v.s)*(s-v.e))<=0)||
				(d4==0 &&sgn((e-v.s)*(e-v.e))<=0);
	}
	
	int relation(Point p){
			int c=sgn((p-s)^(p-e));
			if(c<0)return 1;
			else if(c>0) return 2;
			else return 3;
		}
		bool parallel(Line v){
			return sgn((e-s)^(v.e-v.s))==0;
		}
		//直线与直线相交判断
		//0 平行
		//1 重合
		//2 相交
		int line_cross_line(Line v){
			if((*this).parallel(v))
			return v.relation(s)==3;
			return 2;
		}
} l[100005];

int n;
queue <pair <Line, int> > q;

int main() {	
	while(~scanf("%d", &n) && n) {
		double x[2], y[2];
		for(int i = 1;i <= n; i++) {
			scanf("%lf %lf %lf %lf", &x[0], &y[0], &x[1], &y[1]);
			l[i] = Line(Point(x[0], y[0]), Point(x[1], y[1]));
		}
		q.push({l[1], 1});
		
		for(int i = 2;i <= n; i++) {
			int size = q.size();
			while(size--) {
				pair <Line, int> now = q.front(); q.pop();
				int res = now.first.seg_cross_seg(l[i]);
				if(res == 0) {
					q.push(now);
				}
			}
			q.push({l[i], i});
		}
		
		printf("Top sticks: ");
		while(!q.empty()) {
			pair <Line, int> res = q.front(); q.pop();
			printf("%d", res.second);
			printf("%s", q.empty()?".": ", ");
		}
		puts("");
	}
}