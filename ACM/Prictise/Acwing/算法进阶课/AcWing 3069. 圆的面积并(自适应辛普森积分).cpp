#include <bits/stdc++.h>
using namespace std;
const int N = 1003;
const double eps = 1e-5;

int n;
struct circle {
	double x, y;
	double r;
	void input() {
		scanf("%lf %lf %lf", &x, &y, &r);
	}
} c[N];

double dist(double a, double b, double c, double d) {
	return sqrt((a-c)*(a-c) + (b-d)*(b-d));
}

double f(double x) {
	vector <pair<double, double> > res, ans;
	for(int i = 0; i < n; i++) {
		if(fabs(x - c[i].x) < c[i].r) {
			double cha = fabs(x - c[i].x);
			double dis = sqrt(c[i].r*c[i].r - cha*cha);
			res.push_back({c[i].y-dis, c[i].y+dis});
		}
	}
	sort(res.begin(), res.end());
	
	if(!res.empty()) {
		double l = res[0].first, r = res[0].second;
		for(int i = 1; i < res.size(); i++) {
			if(l <= res[i].first && res[i].second <= r) continue;
			if(res[i].first > r) {
				ans.push_back({l, r});
				l = res[i].first;
				r = res[i].second;
			}
			else {
				r = res[i].second;
			}
		}
		ans.push_back({l, r});
	}
	
	double sum = 0;
	for(auto i: ans) {
		sum += i.second - i.first;
	}
	return sum;
}

double simpson(double l, double r) {
	return (r - l) * (f(l) + 4 * f((r+l)/2) + f(r)) / 6;
}

double solve(double l, double r) {
	double s = simpson(l, r);
	double mid = (l + r) / 2;
	double ls = simpson(l, mid), rs = simpson(mid, r);
	if(fabs(ls + rs - s) < eps) return ls + rs;
	return solve(l, mid) + solve(mid, r);
}

int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		c[i].input();
	}
	
	printf("%.3f\n", solve(-2000, 2000));
}