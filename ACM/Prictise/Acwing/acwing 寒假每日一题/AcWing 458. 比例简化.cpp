#include <bits/stdc++.h>
using namespace std;

int a, b, l;

bool check() {
	return a <= l && b <= l;
}

int main() {
	scanf("%d %d %d", &a, &b, &l);
	int gc = __gcd(a, b);
	a /= gc; b /= gc;
	if(check()) return printf("%d %d\n", a, b), 0;
	double bl = (double) a / b;
	double cha = 1e9;
	for(int i = 1;i <= l; i++) {
		for(int j = 1;j <= l; j++) {
			double now = (double) i / j;
			if(now >= bl && cha > now-bl) {
				cha = now - bl;
				a = i, b = j;
			}
		}
	}
	
	printf("%d %d\n", a, b);
}