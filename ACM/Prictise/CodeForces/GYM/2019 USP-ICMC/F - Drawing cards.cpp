#include <bits/stdc++.h>
using namespace std;

int n;
double ans;

int main() {
	scanf("%d", &n);
	double j = 1.0;
	for(int i = 1;i <= n; i++) {
		ans += j;
		j += 1.0;
	}
	ans /= (double)n;
	printf("%.8lf", ans);
}