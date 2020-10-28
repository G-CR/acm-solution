## Space Ant [POJ - 1696](https://vjudge.net/problem/POJ-1696/origin)

题意：给n个带有序号的食物，然后有一只蚂蚁只会向左和向前走，问🐜最后能吃到最多多少个食物并打印食用顺序。

思路：肯定可以选择一种策略使得蚂蚁最终把所有的食物吃完。可以这样吃：从外围的食物向内转圈吃，每一次吃的都是最外面的食物就可以。选择一个左下角的点，以这个点为基点，平行于x轴正方向做一条直线，然后在剩余的点中选择使这个角，也就是极角最小的点，下一个点就是它，然后基点调整到这个点继续一样的操作就可以选完所有的点，记录序号就可以了。这样选点就是基于极角排序的方法进行的。

```cpp
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define eps 1e-8
using namespace std;

double sgn(double x) {
	if(fabs(x) < eps)return 0;
	if(x < 0) return -1;
	return 1;
}

struct Point { // 表示点
	double x, y;
	int id;
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
} p[100];

int _, n, pos;
double dist(Point a, Point b) {
	return sqrt((a-b)*(a-b));
}
bool cmp(Point a,Point b) { // 极角排序
	double tmp = (a-p[pos])^(b-p[pos]);
	// 找到与当前点逆时针极角最小的点 把 '<' 改成 '>' 就是找极角最大的点
	if(sgn(tmp) == 0)
		return dist(p[pos],a) < dist(p[pos],b);
	else if(sgn(tmp) < 0)return false;
	else return true;
}


int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 0;i < n; i++) {
			scanf("%d %lf %lf", &p[i].id, &p[i].x, &p[i].y);
			if(p[i].y < p[0].y || (p[i].y == p[0].y && p[i].x < p[0].x)) {
				swap(p[i], p[0]);
			}
		}
		
		pos = 0;
		for(int i = 1;i < n; i++) {
			sort(p+i, p+n, cmp);
			pos++;
		}
		
		printf("%d ", n);
		for(int i = 0;i < n; i++) {
			printf("%d ", p[i].id);
		} puts("");
	}
}
```

