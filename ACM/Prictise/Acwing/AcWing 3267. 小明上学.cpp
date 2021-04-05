#include <bits/stdc++.h>
using namespace std;

int n, k, t;
int r, g, y;

int main() {
	scanf("%d %d %d %d", &r, &g, &y, &n);
	int ans = 0;
	for(int i = 1; i <= n; i++) {
		scanf("%d %d", &k, &t);
		if(k == 0) ans += t;
		else if(k == 1) ans += t;
		else if(k == 2) ans += t + r;
	}
	printf("%d\n" ,ans);
}