#include <bits/stdc++.h>
using namespace std;

const double eps = 1e-15;

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
};

struct Line { // 表示线段
	Point s,e;
	Line(){}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	} 
	// 判断直线相交的，无需要可以不用（相交返回交点的版本，下面有一个只做判断的版本）
	// 返回pair first为0重合 为1平行 为2相交且second为交点
	pair <int, Point> operator & (const Line &b)const { 
		Point res = s;
		if(sgn((s-e)^(b.s-b.e)) == 0) {
			if(sgn((b.s-s)^(b.e-s)) == 0)
				return make_pair(0,res);//两直线重合
			else return make_pair(1,res);//两直线平行
		}
		double t = ((s-b.s)^(b.s-b.e))/((s-e)^(b.s-b.e));
		res.x += (e.x - s.x)*t;
		res.y += (e.y - s.y)*t;
		return make_pair(2,res);//有交点
	}
};

bool inter(Line l1,Line l2) {
	return
	max(l1.s.x,l1.e.x) >= min(l2.s.x,l2.e.x) &&
	max(l2.s.x,l2.e.x) >= min(l1.s.x,l1.e.x) &&
	max(l1.s.y,l1.e.y) >= min(l2.s.y,l2.e.y) &&
	max(l2.s.y,l2.e.y) >= min(l1.s.y,l1.e.y) &&
	sgn((l2.s-l1.e)^(l1.s-l1.e))*sgn((l2.e-l1.e)^(l1.s-l1.e)) <= 0 &&
	sgn((l1.s-l2.e)^(l2.s-l2.e))*sgn((l1.e-l2.e)^(l2.s-l2.e)) <= 0;
}

int n;
Point p[700005];
Line l[700005];

bool iszheng(double x) {
	long long wtf = x;
	if(sgn(x-wtf) == 0) return 1;
	return 0;
}

int main() {
	while(~scanf("%d", &n)) {
		int numl = 0;
		for(int i = 0;i < n; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
			if(i) l[numl++] = Line(p[i-1], p[i]);
		}
		
		set <long long> st; st.clear();
		Line x = Line(Point(0,0), Point(1,0));
		
		// 射线与x轴重合
		if((l[0] & x).first == 0 || (l[numl-1] & x).first == 0) {
			puts("-1");
			continue;
		}
		
		// 第一条射线判断
		if((p[1].y > p[0].y && p[1].y > 0) || (p[1].y < p[0].y && p[1].y < 0)) {
			Point t = (l[0] & x).second;
			double res = t.x;
			if(iszheng(res)) st.insert((long long)res);
		}
        
        // 最后一条射线判断
        if((p[n-1].y > p[n-2].y && p[n-2].y < 0) || (p[n-1].y < p[n-2].y && p[n-2].y > 0)) {
            Point t = (l[numl-1] & x).second;
            double res = t.x;
            if(iszheng(res)) st.insert((long long)res);
        }
		
		bool ok = 1;
		for(int i = 1;i < numl-1; i++) {
			// 线段与x轴重合的情况
			if((l[i] & x).first == 0) {
				for(long long j = l[i].s.x; j <= l[i].e.x; j++) {
					st.insert(j);
					if(st.size() > 300000) {ok = 0; break;} 
				}
				if(!ok) break;
			}
			else {
				// 线段与x轴相交
				Line xx = Line(Point(l[i].s.x, 0), (Point(l[i].e.x, 0)));
				if(inter(l[i], xx)) {
					Point t = (l[i] & xx).second;
					double res = t.x;
					if(iszheng(res)) st.insert((long long)res);
				}
			}
			
			if(st.size() > 300000) break;
		}
		
		if(st.size() > 300000) puts("-1");
		else {
			printf("%d\n", (int)st.size());
			for(long long i: st) printf("%lld ", i);
		}
		puts("");
	}
}