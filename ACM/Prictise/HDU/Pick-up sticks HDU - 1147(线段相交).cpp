#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int n;

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
} l[100005];

bool vis[100005];


int main() {
	while(~scanf("%d", &n) && n) {
		Point a, b;
		for(int i = 1;i <= n; i++) {
			scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
			l[i] = Line(a, b);
			vis[i] = 0;
		}
		
		for(int i = 1;i <= n; i++) {
			for(int j = i+1;j <= n; j++) {
				if(l[i].seg_cross_seg(l[j])) {
					vis[i] = 1;
					break;
				}
			}
		}
		
		vector <int> ans;
		for(int i = 1;i <= n; i++) if(!vis[i]) ans.push_back(i);
		printf("Top sticks: ");
		for(int i = 0;i < ans.size(); i++) {
			printf("%d%s", ans[i], i == ans.size()-1?".":", ");
		} puts("");
	}
}