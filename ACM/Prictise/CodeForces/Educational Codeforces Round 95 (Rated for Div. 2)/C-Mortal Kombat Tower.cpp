#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[200005], dp[200005][2][3];

int dfs(int p, int lun, int cnt) {
	if(p == n+1) return 0;
	if(dp[p][lun][cnt] >= 0) return dp[p][lun][cnt];
	if(lun == 0) {
		if(a[p] == 1) {
			if(cnt == 1) return dp[p][lun][cnt] = min(dfs(p+1, lun, 2), dfs(p+1, !lun, 1))+1;
			else return dp[p][lun][cnt] = dfs(p+1, !lun, 1)+1;
		}
		else if(a[p] == 0) {
			if(cnt == 1) return dp[p][lun][cnt] = min(dfs(p+1, lun, 2), dfs(p+1, !lun, 1));
			else return dp[p][lun][cnt] = dfs(p+1, !lun, 1);
		}
	}
	else if(lun == 1) {
		if(cnt == 1) return dp[p][lun][cnt] = min(dfs(p+1, lun, 2), dfs(p+1, !lun, 1));
		else return dp[p][lun][cnt] = dfs(p+1, !lun, 1);
	}
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			for(int j = 0;j <= 1; j++) {
				for(int k = 1;k <= 2; k++) {
					dp[i][j][k] = -1;
				}
			}
		}
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		printf("%d\n", dfs(1, 0, 1));
	}
}