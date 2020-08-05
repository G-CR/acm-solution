// https://ac.nowcoder.com/acm/contest/5891/B
#include <bits/stdc++.h>
using namespace std;

int _;
long long y, p;

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
	scanf("%d", &_);
	while(_--) {
		scanf("%lld %lld", &y, &p);
		if(y%p == 0) puts("-1");
		else {
			long long x, num;
			exgcd(p,y,num,x);
			while(x < 0) x += p;
			printf("%lld\n", x%p);
		}
	}
}