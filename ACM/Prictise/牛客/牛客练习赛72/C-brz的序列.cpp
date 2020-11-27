#include <bits/stdc++.h>
using namespace std;

int n;
double a[1000006];
int b[1000006];

bool check(int x, int y, int z) {
	return (a[y]-a[x])*(y-z)-(a[y]-a[z])*(y-x) < 0;
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%lf", &a[i]);
	}
	
	int top = 0;
	for(int i = 1;i <= n; i++) {
		while(top >= 2 && check(b[top-1], b[top], i)) top--; 
		b[++top] = i;
	}
	
	double ans = 0;
	for(int i = 2;i <= top; i++) {
		ans += (a[b[i-1]] + a[b[i]]) * (b[i]-b[i-1]+1) / 2.0;
	}
	
	for(int i = 2;i <= top-1; i++) ans -= a[b[i]];
	
	printf("%.10lf", ans);
}