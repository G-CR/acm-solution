#include <bits/stdc++.h>
using namespace std;

int n;
int a[102][102];

int main() {
	while(~scanf("%d", &n) && n) {
		for(int i = 1;i <= n; i++) {
			a[1][i] = i;
			a[i][1] = i;
		}
		for(int i = 2;i <= n; i++) {
			for(int j = 2;j <= n; j++) {
				a[i][j] = a[i-1][j-1];
			}
		}
		
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= n; j++) {
				printf("%d ", a[i][j]);
			}
			puts("");
		}
		puts("");
	}
}