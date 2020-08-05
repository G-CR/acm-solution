#include <bits/stdc++.h>
using namespace std;

int T, n, k, x;
int t[4];
int ans[2005];
int main() {
	scanf("%d", &T);
	while(T--) {
		int cnt = 0, num = 0;
		scanf("%d %d", &n, &k);
		for(int i = 1;i <= n; i++) {
			num = 0;
			for(int j = 1;j <= 3; j++) {
				scanf("%d", &x);
				t[++num] = x;
			}
			sort(t+1, t+4);
			ans[++cnt] = t[1]; ans[++cnt] = t[2];
		}
		
		sort(ans+1, ans+1+cnt);
		long long sum = 0;
		for(int i = 1;i <= k; i++) {
			sum += ans[i];
		}
		
		printf("%lld\n", sum);
	}
}