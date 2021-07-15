#include <bits/stdc++.h>
using namespace std;

int n;
double x, ma = -1, mi = 101, sum;

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%lf", &x);
		sum += x;
		ma = max(ma, x);
		mi = min(mi, x);
	}
	
	printf("%.0f\n%.0f\n%.2f\n", ma, mi, sum/n);
}