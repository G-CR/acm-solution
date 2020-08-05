#include <bits/stdc++.h>
using namespace std;

int a[305][305];

int main() {
	int n;
	scanf("%d", &n);
	int cnt = 1, pos = 1, val = 1,i;
	
	cnt = 1;
	for(int j = 1;j <= n; j += 2) {
		for(int i = 1;i <= n; i++) {
			a[i][j] = cnt++;
		}
		cnt += n;
	}
	
	cnt = n+1;
	for(int j = 2;j <= n; j += 2) {
		for(int i = n;i >= 1; i--) {
			a[i][j] = cnt++;
		}
		cnt += n;
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= n; j++) {
			printf("%d ", a[i][j]);
		}
		puts("");
	}
}