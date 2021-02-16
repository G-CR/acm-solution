#include <bits/stdc++.h>
using namespace std;

double a, R;
double pi = acos(-1);

int main() {
	scanf("%lf %lf", &a, &R);
	//(高:sqrt(6)/3; 外接圆半径:sqrt(6)/4)
	double d = a * sqrt(6) / 12; // 中心到平面距离
	double r = sqrt(R*R - d*d);
	double ans = 0;
	if(R <= d) ans = 0;
	else if(r <= a / (sqrt(3) * 2)) ans = 4 * pi * r * r;
	else if(R >= a / 4 * sqrt(6)) ans = a * a * sqrt(3);
	else {
		double df = a / (sqrt(3) * 2);
		double fk = sqrt(r*r - df*df);
		double deg = pi / 3 - acos(df/r);
		double s = 0.5 * r * r * deg;
		ans =  fk * df * 3;
		double shan = r * r * 0.5 * deg;
		ans += 6 * shan;
		ans *= 4;
	}
	
	printf("%lf\n", ans);
}

// https://uploadfiles.nowcoder.com/images/20210201/794972751_1612192595568/767FD3EF58D2ADD192B2425AA3860042