#include <bits/stdc++.h>
using namespace std;

int t,b,p,f,h,c;

int main() {
	scanf("%d", &t);
	while(t--) {
		int ans = 0;
		scanf("%d %d %d %d %d", &b, &p, &f, &h, &c);
		if(b < 2) {
			puts("0");
			continue;
		}
		b /= 2;
		if(h > c) {
			ans += h * min(p,b);
			b -= min(p,b);
			ans += c * min(f,b);
		}
		else {
			ans += c * min(f,b);
			b -= min(f,b);
			ans += h * min(p,b);
		}
		printf("%d\n", ans);
	}
}