#include <bits/stdc++.h>
using namespace std;

const double PI = acos(-1.0);
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

double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

double xmult(Point p0,Point p1,Point p2) { 
	return (p1-p0)^(p2-p0);
}

const int N = 40004;
Point poly[N], tmp[N];
int sta[N], top;

//利用极角排序，角度相同则距离小排前面
bool cmp(Point p1, Point p2) {
	double tmp = xmult(poly[0], p1, p2);
	if (tmp > 0)
		return true;
	else if (tmp == 0 && dist(poly[0], p1) < dist(poly[0], p2))
		return true;
	else
		return false;
}

//输入，并把  最左下方的点放在 poly[0] , 并且进行极角排序
void init(int n) {
	int i, k = 0;
	poly[0] = tmp[0];
	Point p0 = poly[0];  // p0 等价于 tmp 去寻找最左下方的点
	for (int i = 1; i < n; ++i) {
		poly[i] = tmp[i];
		if (p0.y > poly[i].y || (p0.y == poly[i].y && p0.x > poly[i].x))
			p0 = poly[i], k = i;
	}
	poly[k] = poly[0];
	poly[0] = p0;
	sort(poly + 1, poly + n, cmp);
}

void Graham(int n) {
	if (n == 1) top = 0, sta[0] = 0;
	if (n == 2) top = 1, sta[0] = 0, sta[1] = 1;
	if (n > 2) {
		for (int i = 0; i <= 1; i++) sta[i] = i;
		top = 1;
		
		for (int i = 2; i < n; i++) {
			while (top > 0 && xmult(poly[sta[top - 1]], poly[sta[top]], poly[i]) <= 0)
				top--;
			top++;
			sta[top] = i;
		}
	}
}

int n;
int dx[] = {1,1,-1,-1};
int dy[] = {-1,1,1,-1};
double h, w, r;

Point rtt(Point a, double d) {
	return {a.x*cos(d)-a.y*sin(d), a.x*sin(d)+a.y*cos(d)};
}

int main() {
	scanf("%d", &n);
	scanf("%lf %lf %lf", &h, &w, &r);
	h = h / 2 - r; w = w / 2 - r;
	int cnt = 0;
	for(int i = 1;i <= n; i++) {
		double x, y, thi;
		scanf("%lf %lf %lf", &x, &y, &thi);
		for(int j = 0;j < 4; j++) {
			Point t = rtt(Point(w*dx[j], h*dy[j]), thi);
			tmp[cnt++] = Point(t.x+x, t.y+y);
//			printf("%.0lf %.0lf\n", tmp[cnt-1].x, tmp[cnt-1].y);
		}
	}
	
	n *= 4;
	init(n);
	Graham(n);
	
	double ans = 2*PI*r + dist(poly[sta[top]], poly[sta[0]]);
	for(int i = 0;i < top; i++) {
		ans += dist(poly[sta[i]], poly[sta[i+1]]);
	}
	
	printf("%.2lf\n", ans);
}