#include <bits/stdc++.h>
using namespace std;

int _;
bool isnot[2000006];
long long zys[2000006];
long long gcd(long long a, long long b) {return b==0?a:gcd(b,a%b);}

void getys() {
	for(long long i = 0;i <= 2000000; i++) zys[i] = i;
	for(long long i=2;i<=2000000;i++){
		if(!isnot[i]) {
			for (long long j = i; j <= 2000000; j += i) {
				isnot[j] = true;
				zys[j] = i;
			}
		}
	}
	zys[0] = zys[1] = 1;
}

void exgcd(long long a, long long b, long long &x, long long &y) {
	if(!b) {
		x = 1;
		y = 0;
	}
	else {
		exgcd(b, a%b, y, x);
		y -= (a/b) * x;
	}
}


int main() {
	getys();
	scanf("%d", &_);
	while(_--) {
		long long _a, _b, a, b;
		scanf("%lld %lld", &_a, &_b);
		long long t = gcd(_a, _b);
		a = _a/t; b = _b/t;
		long long c, d, e, f;
		if(b != _b) {
			e = f = 1;
			c = a+b; d = b;
			printf("%lld %lld %lld %lld\n", c, d, e, f);
		}
		else {
			long long k = zys[b];
			d = 1; f = b;
			while(k != 1 && f%k == 0) {
				d *= k;
				f /= k;
			}
			if(f == 1) {puts("-1 -1 -1 -1"); continue;}
			exgcd(f, d, c, e);
			e = -e;
			while(c <= 0 || e <= 0) {
				c += d;
				e += f;
			}
			c *= a; e *= a;
			printf("%lld %lld %lld %lld\n", c, d, e, f);
		}
	}
}