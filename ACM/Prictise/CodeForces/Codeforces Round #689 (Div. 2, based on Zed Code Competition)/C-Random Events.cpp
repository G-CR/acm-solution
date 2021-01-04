#include <bits/stdc++.h>
using namespace std;

int _, n, m, a[100005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		int pos = 0;
		for(int i = n;i >= 1; i--) {
			if(a[i] != i) {
				pos = i;
				break;
			}
		}
		
		double ans = 1.0, maybe;
		int p;
		for(int i = 1;i <= m; i++) {
			scanf("%d %lf", &p, &maybe);
			if(p >= pos) {
				ans *= (1.0-maybe);
			}
		}
		
		if(pos == 0) {printf("%lf\n", 1.0); continue;}
		printf("%lf\n", 1.0-ans);
	}
}