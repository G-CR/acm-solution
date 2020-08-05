#include <bits/stdc++.h>
using namespace std;

int n,d,e,ans;

int main() {
	scanf("%d %d %d", &n, &d, &e); e *= 5;
	int t = n/d;
	n %= d;
	ans = n;
	for(int i = 1;i <= t; i++) {
		n += d;
		if(n >= e) {
			n -= e;
			ans = min(ans, n);
		}
	}
	printf("%d\n", ans);
}