#include <bits/stdc++.h>
using namespace std;

double x1,x2,x3,y11,y2,y3,x,y;

int main() {
	scanf("%lf %lf %lf %lf %lf %lf", &x1, &y11, &x2, &y2, &x3, &y3);
	x=((y2-y11)*(y3*y3-y11*y11+x3*x3-x1*x1)-(y3-y11)*(y2*y2-y11*y11+x2*x2-x1*x1))/(2.0*((x3-x1)*(y2-y11)-(x2-x1)*(y3-y11)));

	y=((x2-x1)*(x3*x3-x1*x1+y3*y3-y11*y11)-(x3-x1)*(x2*x2-x1*x1+y2*y2-y11*y11))/(2.0*((y3-y11)*(x2-x1)-(y2-y11)*(x3-x1)));
	
	printf("%.3lf %.3lf\n", x, y);
}