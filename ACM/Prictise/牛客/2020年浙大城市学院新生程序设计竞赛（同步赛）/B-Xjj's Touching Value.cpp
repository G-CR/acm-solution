#include <bits/stdc++.h>
using namespace std;

int _;
double a, b, n;
long long p2[32];

double cal(int x) {
	return (double)(a*x+b) / p2[x];
}

int main() {
	p2[0] = 1;
	for(int i = 1;i <= 30; i++) p2[i] = p2[i-1] * 2;
	scanf("%d", &_);
	while(_--) {
		scanf("%lf %lf %lf", &a, &b, &n);
		double ans = -1e18;
		int fz, fm;
		for(int x = 0;x <= n; x++) {
			double now = cal(x);
			if(ans < now) {
				fz = a*x+b;
				fm = p2[x];
				ans = now;
			}
		}
		
		int t = __gcd(fz, fm);
		fz /= t; fm /= t;
		
		if(fz % fm == 0) {
			printf("%d\n", fz/fm);
			continue;
		}
		if(fm < 0) fz = -fz, fm = -fm;
		
		printf("%d/%d\n", fz, fm);
	}
}