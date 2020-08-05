#include <bits/stdc++.h>
using namespace std;

int _, n, a[100005];
int dp[3600];
queue<int> q;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			a[i] %= 3600;
		}
		while(!q.empty()) q.pop();
		memset(dp, 0, sizeof(dp)); dp[0] = 2;
		for(int i = 1;i <= n && dp[0] != 1; i++) {
			for(int j = 0;j < 3600 && dp[0] != 1; j++) {
				if(dp[j]) {
					q.push((j+a[i])%3600);
				}
			}
			
			while(!q.empty()) {
				int t = q.front(); q.pop();
				dp[t] = 1;
			}
		}
		printf("%s\n", dp[0]==1?"YES":"NO");
	}
}