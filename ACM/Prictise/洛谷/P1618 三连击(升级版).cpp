#include <bits/stdc++.h>
using namespace std;

int a, b, c;
bool fin, ok[10];

int gcd(int a, int b) {
	if(b == 0) return a;
	else return gcd(b, a%b);
}

int main() {
	scanf("%d %d %d", &a, &b, &c);
	if(gcd(a,b) == gcd(b,c)) {
		int t = gcd(a,b);
		a /= t; b /= t; c /= t;
	}
	
	for(int i = 1;; i++) {
		memset(ok, 0, sizeof(ok));
		int s = a * i;
		int m = b * i;
		int l = c * i;
		if(s < 123) continue;
		if(l > 987) break;
		
		while(s) ok[s%10] = 1, s /= 10;
		while(m) ok[m%10] = 1, m /= 10;
		while(l) ok[l%10] = 1, l /= 10;
		
		bool con = 1;
		for(int i = 1;i <= 9; i++) {
			if(!ok[i]) {con = 0; break;}
		}
		
		if(con) {
			fin = 1;
			printf("%d %d %d\n", i*a, i*b, i*c);
		}
	}
	if(!fin) puts("No!!!");
}