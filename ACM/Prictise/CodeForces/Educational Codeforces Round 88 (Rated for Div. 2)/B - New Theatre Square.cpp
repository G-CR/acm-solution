#include <bits/stdc++.h>
using namespace std;

int _, n, m, x, y;
char s[105][1005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d %d", &n, &m, &x, &y);
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				scanf(" %c", &s[i][j]);
			}
		}
		
		int ans = 0;
		for(int i = 1;i <= n; i++) {
			for(int j = 1;j <= m; j++) {
				if(s[i][j] == '.') {
					if(j+1<=m && s[i][j+1]=='.' && 2*x>y) {
						ans += y;
						j++;
					}
					else ans += x;
				}
			}
		}
		
		printf("%d\n", ans);
	}
}