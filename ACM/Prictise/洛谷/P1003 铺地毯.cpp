#include <bits/stdc++.h>
using namespace std;

int a[10004][5];
int n, x, y;

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d %d %d", &a[i][1], &a[i][2], &a[i][3], &a[i][4]);
		a[i][3] += a[i][1]; a[i][4] += a[i][2];
	}
	scanf("%d %d", &x, &y);
	
	for(int i = n;i >= 1; i--) {
		if(a[i][1] <= x && a[i][3] >= x && a[i][2] <= y && a[i][4] >= y)
			return printf("%d\n", i), 0;
	}
	puts("-1");
}