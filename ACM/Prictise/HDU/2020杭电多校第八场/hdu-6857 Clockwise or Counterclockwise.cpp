#include <bits/stdc++.h>
using namespace std;

int _;
long long x[4], y[4];

int main() {
	scanf("%d", &_);
	while(_--) {
		for(int i = 1;i <= 3; i++) {
			scanf("%lld %lld", &x[i], &y[i]);
		}
		
		long long a = y[2]-y[1];
		long long b = x[1]-x[2];
		long long c = x[2]*y[1]-x[1]*y[2];
		
		if(a*x[3]+b*y[3]+c > 0) puts("Clockwise");
		else puts("Counterclockwise");
	}
}