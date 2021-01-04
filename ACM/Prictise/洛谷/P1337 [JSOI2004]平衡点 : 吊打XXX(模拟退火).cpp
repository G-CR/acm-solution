#include <bits/stdc++.h>
#define rands (rand()*2-RAND_MAX)*T
using namespace std;
const double eps = 1e-14;
int n;
double x[1003], y[1003], w[1003];
double resx, resy, resw;

double cal(double posx, double posy) {
	double res = 0;
	for(int i = 1;i <= n; i++) {
		double dx = posx - x[i];
		double dy = posy - y[i];
		res += sqrt(dx*dx+dy*dy) * w[i];
	}
	return res;
}

void fire() {
	double T = 10000, D = 0.996;
	while(T > eps) {
		double tx = resx + rands;
		double ty = resy + rands;
		double tw = cal(tx, ty);
		if(resw > tw) {
			resx = tx; resy = ty;
			resw = tw;
		}
		else if(exp((-fabs(resw-tw))/T) > rand()) {
			resx = tx; resy = ty;
		}
		T *= D;
	}
}

void solve() {
	int num = 20;
	while(num--) {
		fire();
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lf %lf %lf", &x[i], &y[i], &w[i]);
		resx += x[i]; resy += y[i];
	}
	resx /= n; resy /= n;
	resw = cal(resx, resy);
	srand(time(NULL));
	solve();
	printf("%.3lf %.3lf\n", resx, resy);
	return 0;
}