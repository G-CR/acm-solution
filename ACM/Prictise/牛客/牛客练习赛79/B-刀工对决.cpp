#include <bits/stdc++.h>
using namespace std;

int main() {
	int n; scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		int a, b; scanf("%d %d", &a, &b);
		if(a == b) continue;
		int t = __gcd(a, b);
		a /= t; b /= t;
		
		int five = 0, three = 0;
		while(a % 5 == 0) five++, a /= 5;
		while(a % 3 == 0) three++, a /= 3;
		
		while(b % 5 == 0) five++, b /= 5;
		while(b % 3 == 0) three++, b /= 3;
		
		if(a != 1 || b != 1) return puts("-1"), 0;
		
		if(five >= three) ans += 2*five-three;
		else ans += three;
	}
	printf("%d\n", ans);
}