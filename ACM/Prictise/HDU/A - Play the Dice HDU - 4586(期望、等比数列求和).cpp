#include <bits/stdc++.h>
using namespace std;

int n, m, x;
double a[202];

int main() {
	while(~scanf("%d", &n)) {
		double avg = 0;
		for(int i = 1;i <= n; i++) scanf("%lf", &a[i]), avg += a[i];
		avg /= (double)n;
		scanf("%d", &m);
		for(int i = 1;i <= m; i++) scanf("%d", &x);
		
		if(avg == 0) puts("0.00");
		else if(m == n) puts("inf");
		else printf("%.2lf\n", avg/(1-(double)m/(double)n));
	}
}