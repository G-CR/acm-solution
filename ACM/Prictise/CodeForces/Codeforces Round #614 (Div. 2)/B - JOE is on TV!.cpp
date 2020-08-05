#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int t = n;
	double ans1 = 0;
	while(n != 1) {
		if(n % 2) {
			ans1 += ((double)n+1)/2/(double)n;
		}
		else {
			ans1 += 0.5;
		}
		n /= 2;
	}
	ans1++;
	n = t;
	double ans2 = 0;
	for(double i = n;i >= 1; i--) {
		ans2 += 1.0/i;
	}
	printf("%lf\n", max(ans1, ans2));
}