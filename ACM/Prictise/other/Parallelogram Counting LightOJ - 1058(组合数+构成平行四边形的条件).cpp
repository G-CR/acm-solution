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
	bool operator == (Point b) const {
		return sgn(x-b.x) == 0 && sgn(y-b.y) == 0;
	}
} p[1003], mid[1000006];

bool cmp(Point a, Point b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}

int _, n;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lf %lf", &p[i].x, &p[i].y);
		}
		int cnt = 0;
		for(int i = 1;i <= n; i++) {
			for(int j = i+1;j <= n; j++) {
				mid[cnt++] = Point((p[i].x+p[j].x)/2, (p[i].y+p[j].y)/2);
			}
		}
		
		sort(mid, mid+cnt, cmp);
		
		int num = 1;
		long long ans = 0;
		for(int i = 1;i < cnt; i++) {
			if(mid[i] == mid[i-1]) num++;
			else {
				ans += (num-1)*num / 2;
				num = 1;
			}
		}
		
		printf("Case %d: %lld\n", ++cas, ans);
	}
}