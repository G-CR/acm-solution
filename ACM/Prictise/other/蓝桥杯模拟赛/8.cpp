#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[103][103];

int cal(int x, int y) {
	int sum = 0, num;
	for(int i = x-1;i <= x+1; i++) {
		for(int j = y-1;j <= y+1; j++) {
			sum += a[i][j];
		}
	}
	
	if((x == 1|| x== n) && (y == 1||y == m)) num = 4;
	else if((x == 1|| x== n) || (y == 1||y == m)) num = 6;
	else num = 9;
	
	return sum / num;
}

int main() {
	scanf("%d %d", &n ,&m);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			printf("%d ", cal(i, j));
		}
		puts("");
	}
	return 0;
}