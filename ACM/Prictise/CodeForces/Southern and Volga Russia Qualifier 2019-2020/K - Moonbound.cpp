#include <bits/stdc++.h>
using namespace std;

int n;

int main() {
	scanf("%d", &n);
	int num = 3*n*n/4;
	printf("%d\n", num);
	
	for(int i = 1;i <= n; i += 2) {
		for(int j = 2;j <= n; j += 2) {
			printf("1 %d %d 2\n", i, j);
			printf("1 %d %d 2\n", i+1, j-1);
			printf("2 %d %d 1\n", i, j-1);
		}
	}
}