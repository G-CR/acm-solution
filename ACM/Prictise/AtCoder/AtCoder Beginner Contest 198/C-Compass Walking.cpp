#include <bits/stdc++.h>
using namespace std;

double r, x, y;
long long a,b,c;
int main() {
	scanf("%lld %lld %lld", &a, &b, &c);
	r=a;
	x=b;
	y=c;
//	double e = (x*x)+(y*y);
	double dis = sqrt((double)(b*b+c*c));
	
	if(dis == r) puts("1");
	else if(dis <= r+r) puts("2");
	else {
		int ans = ceil(dis/r);
//		int ans = (int)((dis+r-1) / r);
		printf("%d\n", ans);
	}
}