#include <bits/stdc++.h>
using namespace std;

int n, m, x, b[1005], num[2005];

int main() {
	while(~scanf("%d %d", &n, &m)) {
		memset(num, 0, sizeof(num));
		
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			num[x]++;
		}
		
		for(int i = 1;i <= m; i++) {
			scanf("%d", &b[i]);
		}
		
		int j,ans;
		for(ans = 0;; ans++) {
			for(j = 1;j <= m; j++) {
				if(num[b[j]+ans]) break;
			}
			if(j == m+1) break;
		}
		printf("%d\n", ans);
	}
}