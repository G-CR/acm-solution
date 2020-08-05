#include <bits/stdc++.h>
using namespace std;
const int INF = 50000;
int p, n, x;
int a[40004];

int main() {
	scanf("%d", &p);
	while(p--) {
		memset(a, INF, sizeof(a));
		int cnt = 0; a[cnt] = 0;
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			if(x > a[cnt]) a[++cnt] = x;
			else {
				int pos = lower_bound(a+1, a+1+n, x) - a;
				a[pos] = x;
			}
		}
		printf("%d\n", cnt);
	}
}




/*   

// DP超时
#include <bits/stdc++.h>
using namespace std;

int p, n;
int dp[40004],a[40004];

int main() {
	scanf("%d", &p);
	while(p--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]); dp[i] = 1;
			for(int j = 1; j <= i-1; j++) {
				if(a[i] > a[j]) {
					dp[i] = max(dp[i], dp[j]+1);
//					printf("dp[%d] = %d\n", i, dp[i]);
				} 
				
			}
		}
		int ans = 1;
		for(int i = 1;i <= n; i++) ans = max(ans, dp[i]);
		printf("%d\n", ans);
	}
}
*/