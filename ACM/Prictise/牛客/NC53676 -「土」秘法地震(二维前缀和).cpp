#include <bits/stdc++.h>
using namespace std;

int n, m, k, sum[1005][1005];
char x;

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf(" %c", &x);
			int a = x-'0';
			sum[i][j] = a + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
		}
	}
	
	int ans = 0;
	for(int i = k;i <= n; i++) {
		for(int j = k;j <= m; j++) {
			if(sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k]) ans++;
		}
	}
	printf("%d\n", ans);
}