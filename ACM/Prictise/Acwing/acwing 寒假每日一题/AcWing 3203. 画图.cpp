#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, d;
bool vis[103][103];

void col(int r1, int c1, int r2, int c2) {
	for(int i = r1; i <= r2; i++) {
		for(int j = c1; j <= c2; j++) {
			vis[i][j] = 1;
		}
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d %d %d %d", &a, &b, &c, &d);
		col(a, b, c-1, d-1);
	}
	
	int ans = 0;
	for(int i = 0;i <= 100; i++) {
		for(int j = 0;j <= 100; j++) {
			if(vis[i][j]) ans++;
		}
	}
	
	printf("%d\n", ans);
}