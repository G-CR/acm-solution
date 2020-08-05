#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	printf("%d\n", n+2*n+4);
	for(int i = 0;i <= n+1; i++) {
		printf("%d %d\n", i, i);
	}

	for(int i = 0;i <= n; i++) {
		printf("%d %d\n", i, i+1);
		printf("%d %d\n", i+1, i);
	}
}