#include <bits/stdc++.h>
using namespace std;

long long n;

int main() {
	scanf("%lld", &n);
	if(n == 2) {puts("1"); return 0;} 
	if(n == 4) {puts("3"); return 0;}
	long long ans = 1;
	long long m = 1, t = n/2, cnt = n/2;
	long long num = n/2;
	while(num) {
		ans *= n;
		ans /= m;
		n--; m++;
		num--;
	}
	ans /= 2;
	
	num = t;
	long long res = 1;
	while(num) {
		res *= t;
		num--; t--;
	}
	res /= cnt;
	printf("%lld\n", ans*res*res);
}