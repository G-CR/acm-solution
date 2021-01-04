#include <bits/stdc++.h>
using namespace std;

int _, n, m;
char s[505][505];
int sum[505][505];
long long ans;




int main() {
	scanf("%d", &_);
	while(_--) {
		ans = 0;
		memset(sum, 0, sizeof(sum));
		scanf("%d %d", &n, &m);
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				scanf(" %c", &s[i][j]);
				if(s[i][j] == '*') sum[i][j] = 1;
			}
		}
		
		for(int i = n;i >= 1; i--) {
			for(int j = 1;j <= m; j++) {
				if(s[i][j] == '*') {
					sum[i][j] += min(min(sum[i+1][j-1], sum[i+1][j]), sum[i+1][j+1]);
				}
			}
		}
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				ans += sum[i][j];
			}
		}
		printf("%lld\n", ans);
	}
}