### [题目链接](https://ac.nowcoder.com/acm/contest/14055/J)

### 题意

一个点走过一条线段，在线段的同一侧有许多点 $ (n ≤ 1000) $ ，随着时间的推移，从线段上的这个点看这些点的视角会发生变化。目光可以抽象成一条直线，顺时针扫过整个平面，然后对于每个点进入视野的时间就会有先后顺序。题目就会问 若干次 $(m ≤ 10000)$  当线段上的点走到哪个位置的时候，对于最初的第h个点第k次交换位置的时候，此时线段上的点的位置。

### 思路

来解释一下样例：

在起点的时候看到的点的顺序是 $(1,3),(2,4),(4,5),(4,1)$ 

然后一直向终点走去

走到 $(4,0)$ 的时候，这时候是一个临界点，可以发现 $(4,1),(4,4)$ 并列了，只要再向终点移动一点点，看到点的顺序就变成 $(1,3),(2,4),(4,1),(4,5)$ 了。

再往终点走一点点，发现走到 $(2,4) , (4,1)$ 与线段的交点时 ，再往终点走一点点，就可以发现顺序又产生变化了 $(1,3),(4,1),(2,4),(4,5)$ 这时候对于 $(4,1)$ 这个点已经交换过两次了。

这个过程容易让人想到：对于给定点，做其余点与这个点的连线，相交于给定线段的时候，此时就会产生视角的变化。然后题目要我们给出第k次变化时点的坐标，所以就需要把所有的交点都先存起来，然后以每个点对于起点的距离作为关键字排序就好了。

### 代码

```cpp
#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld PI = acos(-1.0);
const ld eps = 1e-6;

int sgn(ld x) {
	if(fabs(x) < eps) return 0;
	if(x < 0) return -1;
	else return 1;
}

struct Point {
	ld x, y;
	Point() {}
	Point(ld _x, ld _y) {
		x = _x; y = _y;
	}
	void input() {
		scanf("%Lf %Lf", &x, &y);
	}
	Point operator + (const Point &b) const {
		return Point(x+b.x, y+b.y);
	}
	Point operator - (const Point &b) const {
		return Point(x-b.x, y-b.y);
	}
	ld operator * (const Point &b) const {
		return x * b.x + y * b.y;
	}
	ld operator ^ (const Point &b) const {
		return x * b.y - y * b.x;
	}
	bool operator < (Point b) const {
		return sgn(x-b.x) == 0 ? sgn(y-b.y) < 0 : x < b.x;
	}
	bool operator == (Point b) const {
		return sgn(x - b.x) == 0 && sgn(y - b.y) == 0;
	}
};

ld dist(Point a, Point b) {
	return sqrt((b-a) * (b-a));
}

struct Line {
	Point s, e;
	Line() {}
	Line(Point _s, Point _e) {
		s = _s; e = _e;
	}
	void input() {
		s.input();
		e.input();
	}
	
	pair <int, Point> operator & (const Line &b) const {
		Point res = s;
		if(sgn((s-e) ^ (b.s-b.e)) == 0) {
			if(sgn((b.s-s) ^ (b.e-s)) == 0)
				return {0, res};
			else return {1, res};
		}
		ld t = ((s-b.s) ^ (b.s-b.e)) / ((s-e) ^ (b.s-b.e));
		res.x += (e.x - s.x) * t;
		res.y += (e.y - s.y) * t;
		return {2, res};
	}
	
	int seg_cross_seg(Line v) {
		int d1 = sgn((e-s) ^ (v.s-s));
		int d2 = sgn((e-s) ^ (v.e-s));
		int d3 = sgn((v.e-v.s) ^ (s-v.s));
		int d4 = sgn((v.e-v.s) ^ (e-v.s));
		if((d1 ^ d2) == -2 && (d3 ^ d4) == -2) return 2;
		return (d1 == 0 && sgn((v.s-s) * (v.s-e)) <= 0) ||
			(d2 == 0 && sgn((v.e-s)*(v.e-e)) <= 0) ||
			(d3 == 0 && sgn((s-v.s)*(s-v.e)) <= 0) ||
			(d4 == 0 && sgn((e-v.s)*(e-v.e)) <= 0);
	}
};

bool onseg(Point P,Line L) {
	return
		sgn((L.s-P)^(L.e-P)) == 0 &&
		sgn((P.x - L.s.x) * (P.x - L.e.x)) <= 0 &&
		sgn((P.y - L.s.y) * (P.y - L.e.y)) <= 0;
}

int n, m;
Line sg;
Point p[1003];
vector <Point> v;

bool cmp(Point a, Point b) {
	return dist(a, sg.s) < dist(b, sg.s);
}

int main() {
	scanf("%d %d", &n, &m);
	sg.input();
	for(int i = 1; i <= n; i++) p[i].input();
	while(m--) {
		int id, cnt; scanf("%d %d", &id, &cnt);
		v.clear();
		for(int i = 1; i <= n; i++) {
			if(i == id) continue;
			Line l (p[id], p[i]);
			auto t = sg & l;
			int cs = t.first;
			if(cs == 2) {
				Point csp = t.second;
				if(onseg(csp, sg))
					v.push_back(csp);
			}
		}
		
		if(v.size() < cnt) puts("-1");
		else {
			sort(v.begin(), v.end(), cmp);
			printf("%.10Lf %.10Lf\n", v[cnt-1].x, v[cnt-1].y);
		}
	}
}
```

