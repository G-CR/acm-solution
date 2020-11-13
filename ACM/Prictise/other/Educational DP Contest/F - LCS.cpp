#include <bits/stdc++.h>
using namespace std;

int dp[3002][3002];
char s[3002], t[3002];
struct node {
	int x, y;
} pre[3002][3002];

int main() {
	scanf("%s %s", (s+1), (t+1));
	int n = strlen(s+1);
	int m = strlen(t+1);
	node lin;
	memset(dp, 0, sizeof(dp));
	
	for(int i = 1;i <= n; i++) {
		for(int j = 1;j <= m; j++) {
			if(s[i] == t[j]) {
				dp[i][j] = dp[i-1][j-1]+1;
				lin.x = i-1; lin.y = j-1;
				pre[i][j] = lin;
			}
			else {
				if(dp[i-1][j] > dp[i][j-1]) {
					lin.x = i-1; lin.y = j;
					pre[i][j] = lin;
					dp[i][j] = dp[i-1][j];
				} 
				else {
					lin.x = i; lin.y = j-1;
					pre[i][j] = lin;
					dp[i][j] = dp[i][j-1];
				}
			}
		}
	}
	
	string ans = "";
	
	int i = n, j = m;
	while(i > 0){
		lin.x = i-1;
		lin.y = j-1;
//		cout << pre[i][j].x << " " << pre[i][j].y << endl;
		if(pre[i][j].x == lin.x && pre[i][j].y == lin.y) {
			ans += s[i];
//			cout << " ! " << endl;
		}
		int tx = i, ty = j;
		i = pre[tx][ty].x;
		j = pre[tx][ty].y;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}