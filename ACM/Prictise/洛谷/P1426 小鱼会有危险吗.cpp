#include <bits/stdc++.h>
using namespace std;

int s, x;

int main() {
	scanf("%d %d", &s, &x);
	int l = s-x, r = s+x;
	double sta = 7;
	double res = 0;
	bool ok = 1, lg = 0;
	while(1) {
		if(lg && res <= r) break;
		if(l <= res && !lg) {
			lg = 1;
			if(res+sta > r) {
				ok = 0;
				break;
			}
		}
		res += sta;
		sta *= 0.98;
	}
	
	if(ok) puts("y");
	else puts("n");
	
}