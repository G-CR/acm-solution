#include <bits/stdc++.h>
using namespace std;

int n;
int a[105];

int main() {
	scanf("%d", &n);
	a[1] = 1; a[2] = 5;
	int m = 1;
	for(int i = 3;i <= 100; i++) {
		a[i] = a[i-1] + m*4 + 4;
		m++;
	}
	printf("%d\n", a[n]);
}