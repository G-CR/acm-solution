#include <bits/stdc++.h>
using namespace std;

int t, n, x, a, b;

int main() {
	scanf("%d", &t);
	while(t--) {
		scanf("%d %d %d %d", &n, &x, &a, &b);
		int front = min(a,b)-1;
		int tail = n-max(a,b);
		int t1 = min(x, max(front, tail)), t2 = 0;
		x -= min(x, max(front, tail));
		if(x) {
			t2 = min(x, min(front, tail));
			x -= min(x, min(front, tail));
		}
		int ans = max(a,b)-min(a,b)+t1+t2;
		printf("%d\n", ans);
	}
}