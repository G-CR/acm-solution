#include <bits/stdc++.h>
using namespace std;

int n;
int a[103][103], pre[103][103];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= n; j++) {
			scanf("%d", &a[i][j]);
			pre[i][j] = pre[i-1][j] + a[i][j];
		}
	}
	
	int ans = -1e9;
	for(int r1 = 1; r1 <= n; r1++) {
		for(int r2 = r1; r2 <= n; r2++) {
			int now = 0;
			for(int c = 1; c <= n; c++) {
				now = max(now, 0) + pre[r2][c]-pre[r1-1][c];
				ans = max(ans, now);
			}
		}
	}
	
	printf("%d\n", ans);
}