#include <bits/stdc++.h>
using namespace std;

int t, k, d, n;
int a[200005];
int num[1000006];
int main() {
	scanf("%d", &t);
	while(t--) {
		memset(num, 0, sizeof(num));
		
		scanf("%d %d %d", &n, &k, &d);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		int ans = 1000006;
		int tot = 0;
		for(int i = 1;i <= d; i++) {
			if(num[a[i]] == 0) tot++;
			num[a[i]]++;
		}
		ans = min(ans, tot);
		for(int i = 2;i <= n-d+1; i++) {
			if(num[a[i+d-1]] == 0) tot++;
			num[a[i+d-1]]++;
			
			num[a[i-1]]--;
			if(num[a[i-1]] == 0) {
				tot--;
			}
			ans = min(ans, tot);
		}
		printf("%d\n", ans);
	}
}