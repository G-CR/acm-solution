#include <bits/stdc++.h>
using namespace std;

int n;
struct Point {
	double x, y;
} a[2005];
vector<pair<double, double> > mp, num;

pair<double, double> solve(Point a, Point b, Point c) {
	double X, Y;
	double fm1=2 * (a.y - c.y) * (a.x - b.x) - 2 * (a.y - b.y) * (a.x - c.x);
	double fm2=2 * (a.y - b.y) * (a.x - c.x) - 2 * (a.y - c.y) * (a.x - b.x);
 
	if (fm1 == 0 || fm2 == 0) {
		X = Y = 1e18;
		return make_pair(X, Y);
	}
	double fz1=a.x * a.x - b.x * b.x + a.y * a.y - b.y * b.y;
	double fz2=a.x * a.x - c.x * c.x + a.y * a.y - c.y * c.y;
	X = (fz1 * (a.y - c.y) - fz2 * (a.y - b.y)) / fm1;
	Y = (fz1 * (a.x - c.x) - fz2 * (a.x - b.x)) / fm2;
	return make_pair(X, Y);
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lf %lf", &a[i].x, &a[i].y);
	}
	
	pair <double, double> cir;
	Point sour; sour.x = 0; sour.y = 0;
	for(int i = 1;i <= n; i++) {
		for(int j = i+1;j <= n; j++) {
			cir = solve(sour, a[i], a[j]);
			if(cir.first == 1e18 && cir.second == 1e18) continue;
//			printf("%lf %lf\n", cir.first, cir.second);
			mp.push_back(cir);
		}
	}
	if(mp.empty()) {puts("1"); return 0;} 
	sort(mp.begin(), mp.end());
	num.push_back(mp[0]);
	int ans = 1;
	for(int i = 1;i < mp.size(); i++) {
		if(mp[i] != num[0]) num.clear();
		num.push_back(mp[i]);
		ans = max(ans, (int)num.size());
	}
	
	for(int i = 1;i <= n; i++) {
		if(i*(i-1) == ans*2) {
			printf("%d\n", i);
			return 0;
		}
	}
}