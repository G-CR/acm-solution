#include <bits/stdc++.h>
using namespace std;
const int mod = 1e4+7;
bool cute[102][102][mod];
int a[102][102];
int n, m;

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	
	cute[0][1][0] = cute[1][0][0] = 1;
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			for(int k = 0;k < mod; k++) {
				int pr = ((k - a[i][j]%mod)+mod)%mod;
				cute[i][j][k] |= (cute[i-1][j][pr] | cute[i][j-1][pr]);
//				printf("%d %d %d %d\n", i, j, k, cute[i][j][k]);
			}
		}
	}
	
	int ans = 0;
	for(int i = 0;i < mod; i++) {
		if(cute[n][m][i]) ans++;
	}
	
	printf("%d\n", ans);
}