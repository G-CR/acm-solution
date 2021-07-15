#include <bits/stdc++.h>
using namespace std;
const int maxp = 10004;
const double eps = 1e-8;
const double inf = 1e20;

struct Point {
	double x, y;
	Point(){}
	Point(double _x, double _y) {
		x = _x; y = _y;
	}
	void input() {
		scanf("%lf %lf", &x, &y);
	}
	Point operator - (const Point &b) const {
		return Point(x-b.x, y-b.y);
	}
	double operator * (const Point &b) const {
		return x*b.x + y*b.y;
	}
};

double dist(Point a, Point b) {
	return sqrt((b-a) * (b-a));
}

bool cmpx(Point a,Point b){
	return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cmpy(Point a, Point b) {
	return a.y < b.y || (a.y == b.y && a.x < b.x);
}

Point p[maxp], tmpt[maxp];

double closest_pair(int left, int right) {
	double d = inf;
	if(left == right) return d;
	if(left+1 == right) return dist(p[left], p[right]);
	int mid = (left + right) / 2;
	double d1 = closest_pair(left, mid);
	double d2 = closest_pair(mid+1, right);
	d = min(d1, d2);
	int cnt = 0;
	for(int i = left; i <= right; i++) {
		if(fabs(p[mid].x - p[i].x) <= d)
			tmpt[cnt++] = p[i];
	}
	
	sort(tmpt, tmpt+cnt, cmpy);
	
	for(int i = 0; i < cnt; i++) {
		for(int j = i+1; j < cnt && tmpt[j].y - tmpt[i].y < d; j++)
			d = min(d, dist(tmpt[i], tmpt[j]));
	}
	
	return d;
}

int n;

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		p[i].input();
	}
	sort(p, p+n, cmpx);
	printf("%.4lf\n", closest_pair(0, n-1));
}