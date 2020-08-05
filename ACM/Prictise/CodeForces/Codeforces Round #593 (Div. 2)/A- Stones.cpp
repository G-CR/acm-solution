#include <bits/stdc++.h>
using namespace std;

int t, a, b, c;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d", &a, &b, &c);
		int ans = 0;
		int t1;
		t1 = min(c/2, b);
		if(b >= t1) {
			c -= (t1*2);
			b -= t1;
			ans += (3*t1);
		}
		t1 = min(b/2, a);
		if(a >= t1) {
			b -= (2*t1);
			a -= t1;
			ans += (3*t1);
		}
		printf("%d\n", ans);
	}
}