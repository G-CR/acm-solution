#include <bits/stdc++.h>
using namespace std;

int _;
int mx, my, n;
double x[1003], y[1003];
double anslen, ansx, ansy;
double sumx, sumy;

double cal(double a, double b) {
	double res = 1e18;
	for(int i = 1;i <= n; i++) {
		double delx = a-x[i];
		double dely = b-y[i];
		res = min(res, sqrt(delx*delx+dely*dely));
	}
	return res;
}

void sa() {
	double resx = ansx, resy = ansy;
	double T = 100;
	double D = 0.996;
	while(T > 1e-5) {
		double angle = double(rand()%1000+1)/1000.0*2.0*acos(-1);
		double delx = T * cos(angle);
		double dely = T * sin(angle);
		double nowx = abs(resx + delx);
		double nowy = abs(resy + dely);
		if(nowx > mx || nowx < 1e-5 || nowy > my || nowy < 1e-5) continue;
		double nowlen = cal(nowx, nowy);
		if(nowlen > anslen) {
			anslen = nowlen;
			ansx = resx = nowx;
			ansy = resy = nowy;
		}
		else if(exp((nowlen-anslen)/T)*RAND_MAX > rand()){
			resx = nowx;
			resy = nowy;
		}
		T *= D;
	}
}

void solve() {
	int num = 100;
	while(num--) {
		sa();
	}
}

int main() {
	srand(time(NULL));
	scanf("%d", &_);
	while(_--){
		double sumx = 0, sumy = 0;
		scanf("%d %d %d", &mx, &my, &n);
		for(int i = 1;i <= n; i++) {
			scanf("%lf %lf", &x[i], &y[i]);
			sumx += x[i]; sumy += y[i];
		}
		anslen = 0;
		ansx = sumx / n;
		ansy = sumy / n;
		solve();
		printf("The safest point is (%.1lf, %.1lf).\n", ansx, ansy);
	}
}