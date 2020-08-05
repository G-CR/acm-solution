#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int ok[55][55], m, n;
char a[55][55];

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	
	ok[1][1] = 1;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			if(a[i-1][j] == 'B' || a[i-1][j] == 'D') ok[i][j] = (ok[i][j]+ok[i-1][j])%mod ;
			if(a[i][j-1] == 'B' || a[i][j-1] == 'R') ok[i][j] = (ok[i][j] + ok[i][j-1])%mod ;
		}
	}
	printf("%d\n", ok[n][m]);
}