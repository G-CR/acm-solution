#include <bits/stdc++.h>
using namespace std;

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


const int N = 10003;
Point poly[N];
int sta[N], top;

// 三个点计算叉积 p0p1 ^ p0p2
double xmult(Point p0,Point p1,Point p2) {
	return (p1-p0)^(p2-p0);
}

//两点距离
double dist(Point a,Point b) {
	return sqrt((b-a)*(b-a));
}

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
	cin >> poly[0].x >> poly[0].y;
	Point p0 = poly[0];  // p0 等价于 tmp 去寻找最左下方的点
	for (int i = 1; i < n; ++i) {
		cin >> poly[i].x >> poly[i].y;
		if (p0.y > poly[i].y || (p0.y == poly[i].y && p0.x > poly[i].x))
			p0 = poly[i], k = i;
	}
	poly[k] = poly[0];
	poly[0] = p0;
	sort(poly + 1, poly + n, cmp);
}

//graham扫描法求凸包，凸包顶点存在sta栈中
//从栈底到栈顶一次是逆时针方向排列的
//如果要求凸包的一条边有2个以上的点
//那么要将while中的<=改成<
//但这不能将最后一条边上的多个点保留
//因为排序时将距离近的点排在前面
//那么最后一条边上的点仅有距离最远的会被保留，其余的会被出栈
//所以最后一条边需要特判
//如果要求逆凸包的话需要改cmp，graham中的符号即可
void Graham(int n) {
	if (n == 1) top = 0, sta[0] = 0;
	if (n == 2) top = 1, sta[0] = 0, sta[1] = 1;
	if (n > 2) {
		for (int i = 0; i <= 1; i++) sta[i] = i;
		top = 1;
		
		for (int i = 2; i < n; i++) {
			while (top > 0 && xmult(poly[sta[top - 1]], poly[sta[top]], poly[i]) < 0)
				top--;
			top++;
			sta[top] = i;
		}
	}
}

int main() {
	int n;
	scanf("%d", &n);
	init(n);
	Graham(n);
	
	double ans = dist(poly[sta[top]], poly[sta[0]]);
	for(int i = 0;i < top; i++) {
		ans += dist(poly[sta[i]], poly[sta[i+1]]);
	}
	printf("%.2lf\n", ans);
}