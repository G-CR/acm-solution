#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const long double eps = 1e-18;
const int maxp = 10004;
int ans[maxp];

int sgn(long double x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point {
	long double x, y;
	Point() {}
	Point(long double _x, long double _y) {
		x = _x; y = _y;
	}
	Point operator + (const Point &b) const {
		return Point(x+b.x, y+b.y);
	}
	Point operator - (const Point &b) const {
		return Point(x-b.x, y-b.y);
	}
	long double operator * (const Point &b) const {
		return x*b.x+y*b.y;
	}
	long double operator ^ (const Point &b) const {
		return x*b.y-y*b.x;
	}
	bool operator < (Point b) const {
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0: x < b.x;
	}
	bool operator == (Point b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
};

struct Line {
	Point s, e;
	vector <int> v;
	Line() {}
	Line(Point _s, Point _e) {
		s = _s;
		e = _e;
	}
	Line(Point _s, Point _e, vector <int> _v) {
		s = _s;
		e = _e;
		v = _v;
	}
	bool operator == (Line v) {
		return (s == v.s) && (e == v.e);
	}
	
	bool parallel(Line v) {
		return sgn((e-s) ^ (v.e-v.s)) == 0;
	}
	
	Point crosspoint(Line v) {
		long double a1 = (v.e-v.s) ^ (s-v.s);
		long double a2 = (v.e-v.s) ^ (e-v.s);
		return Point((s.x*a2-e.x*a1)/(a2-a1), (s.y*a2-e.y*a1)/(a2-a1));
	}
};

struct polygon {
	int n;
	Point p[maxp];
	Line l[maxp];
	
	void getline() {
		for(int i = 0;i < n; i++) {
			l[i] = Line(p[i], p[(i+1)%n]);
		}
	}
	
	long double getarea() {
		long double sum = 0;
		for(int i = 0;i < n; i++) {
			sum += (p[i] ^ p[(i+1)%n]);
		}
		return fabs(sum) / 2;
	}
};

struct halfplane: public Line {
	long double angle;
	halfplane() {}
	halfplane(Point _s, Point _e) {
		s = _s;
		e = _e;
	}
	halfplane(Point _s, Point _e, vector <int> _v) {
		s = _s;
		e = _e;
		v = _v;
	}
	halfplane(Line v) {
		s = v.s;
		e = v.e;
	}
	void calcangle() {
		angle = atan2(e.y-s.y, e.x-s.x);
	}
	bool operator < (const halfplane &b) const {
		return angle < b.angle;
	}
};

struct halfplanes {
	int n;
	halfplane hp[maxp];
	Point p[maxp];
	int que[maxp];
	int st, ed;
	
	void output() {
		for(int i = 0;i < n; i++) {
			printf("(%.0Lf, %.0Lf) (%.0f, %.0Lf)\n", hp[i].s.x, hp[i].s.y, hp[i].e.x, hp[i].e.y);
			for(int j: hp[i].v) printf("%d ", j);
			puts("");
		}
	}
	
	void push(halfplane tmp) {
		hp[n++] = tmp;
	}
	
	void unique() {
		int m = 1;
		for(int i = 1; i < n; i++) {
			if(sgn(hp[i].angle-hp[i-1].angle) != 0)
				hp[m++] = hp[i];
			else if(sgn( (hp[m-1].e-hp[m-1].s) ^ (hp[i].s-hp[m-1].s) ) > 0)
				hp[m-1] = hp[i];
		}
		n = m;
	}
	
	void halfplaneinsert() {
		for(int i = 0;i < n;i++) hp[i].calcangle();
		sort(hp,hp+n);
		unique();
		que[st=0] = 0;
		que[ed=1] = 1;
		p[1] = hp[0].crosspoint(hp[1]);
		for(int i = 2;i < n;i++){
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[ed]-hp[i].s))<0)ed--;
			while(st<ed && sgn((hp[i].e-hp[i].s)^(p[st+1]-hp[i].s))<0)st++;
			que[++ed] = i;
			p[ed]=hp[i].crosspoint(hp[que[ed-1]]);
		}
		
		while(st<ed && sgn((hp[que[st]].e-hp[que[st]].s)^(p[ed]-hp[que[st]].s))<0)ed--;
		while(st<ed && sgn((hp[que[ed]].e-hp[que[ed]].s)^(p[st+1]-hp[que[ed]].s))<0)st++;
		
		int k = 0;
		for(int i = st; i <= ed; i++) {
			for(auto id: hp[que[i]].v) {
				ans[k++] = id+1;
			}
		}
		
		sort(ans, ans+k);
		printf("%d\n", k);
		for(int i = 0;i < k; i++) printf("%d ", ans[i]);
		puts("");
	}
};

int n;
int k[maxp], v[maxp];
halfplane l[maxp];
halfplanes hf;
map <pair <int, int>, vector <int> > mp;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &k[i]);
	for(int i = 0; i < n; i++) scanf("%d", &v[i]);
	for(int i = 0; i < n; i++) mp[{k[i], v[i]}].push_back(i);
	
	int cnt = 0;
	l[cnt++] = halfplane(Point(0, 10000), Point(0, 0));
	l[cnt++] = halfplane(Point(0, 0), Point(10000, 0));
	for(auto i: mp) {
		l[cnt++] = halfplane(Point(0, i.first.first), Point(1, i.first.first+i.first.second), i.second);
	}
	
	hf.n = 0;
	for(int i = 0;i < cnt; i++) {
		hf.push(l[i]);
	}
	
	hf.halfplaneinsert();
}