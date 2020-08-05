#include <bits/stdc++.h>
using namespace std;

int _;
long long x, y;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &x, &y);
		if(y*4 < x) {
			printf("%lld\n", y);
		}
		else if((double)x/(double)y <= (double)2/(double)3) {
			printf("%lld\n", x/2);
		}
		else {
			long long n = (4*y-x+5)/10;
//			cout << "n = " << n << endl;
			x -= 2*n;
			y -= 3*n;
			printf("%lld\n", n + min(x/4, y));
		}
	}
}