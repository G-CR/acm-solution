#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
const double eps = 1e-8;
const int N = 1003;

int sgn(double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point {
	double x, y;
	Point() {}
	Point(double _x, double _y) {
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

double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

struct Line {
	Point s, e;
	Line() {}
	Line(Point _s,Point _e) {
		s = _s;e = _e;
	}
	
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
};

Point p[N];
Line l[N*N];
int n, ln, pn;

void read() {
	p[pn++] = Point(0, 5); p[pn++] = Point(10, 5);
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		double x, y, z; scanf("%lf", &x);
		scanf("%lf", &y);
		p[pn++] = Point(x, 0); p[pn++] = Point(x, y);
		l[ln++] = Line(p[pn-2], p[pn-1]);
		
		scanf("%lf %lf", &y, &z);
		p[pn++] = Point(x, y); p[pn++] = Point(x, z);
		l[ln++] = Line(p[pn-2], p[pn-1]);
		
		scanf("%lf", &y);
		p[pn++] = Point(x, y); p[pn++] = Point(x, 10);
		l[ln++] = Line(p[pn-2], p[pn-1]);
	}
}

bool check(Line v) {
	for(int i = 0; i < ln; i++) {
		if(v.seg_cross_seg(l[i]) == 2) return 0;
	}
	return 1;
}

vector <pair<int, double> > g[N*N];
double d[N];
bool vis[N];

double dij() {
	for(int i = 0; i < 1000; i++) d[i] = 1e9;
	memset(vis, 0, sizeof(vis));
	priority_queue <pair<double, int> > q;
	d[0] = 0;
	q.push({0, 0});
	while(!q.empty()) {
		int now = q.top().second; q.pop();
		if(vis[now]) continue;
		vis[now] = 1;
		for(int i = 0; i < g[now].size(); i++) {
			int to = g[now][i].first;
			double w = g[now][i].second;
			if(d[to] > d[now] + w) {
				d[to] = d[now] + w;
				q.push({-d[to], to});
			}
		}
	}
	
	return d[1];
}

int main() {
	read();
	for(int i = 0; i < pn; i++) {
		for(int j = i+1; j < pn; j++) {
			Line now = Line(p[i], p[j]);
			if(check(now)) {
				double dis = dist(p[i], p[j]);
				g[i].push_back({j, dis});
				g[j].push_back({i, dis});
			}
		}
	}
	
	printf("%.2f\n", dij());
}