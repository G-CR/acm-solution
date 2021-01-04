#include <iostream>
using namespace std;

long long x, y, m, n, l;

long long Exgcd(long long a,long long b,long long &x,long long &y) {
	if(!b) {x = 1,y = 0; return a;}
	long long gcd = Exgcd(b,a%b,x,y), tmp = x;
	x = y,y = tmp-a/b*y;
	return gcd;
}

int main() {
	scanf("%lld %lld %lld %lld %lld", &x, &y, &m, &n, &l);
	long long a = n-m, b = x-y;
	if(a < 0) a = -a, b = -b;
	long long t, z;
	long long gcd = Exgcd(a, l, t, z);
	if(b % gcd) puts("Impossible");
	else printf("%lld\n", ((t*(b/gcd))%(l/gcd)+(l/gcd))%(l/gcd));
	
}