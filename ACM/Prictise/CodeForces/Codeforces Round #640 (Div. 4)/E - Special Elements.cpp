#include <bits/stdc++.h>
using namespace std;

int _, n, x;
int num[8005], pre[8005];

int main() {
	scanf("%d", &_);
	while(_--) {
		memset(pre, 0, sizeof(pre));
		memset(num, 0, sizeof(num));
		
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			num[x]++;
			pre[i] = pre[i-1] + x;
		}
		
		int ans = 0;
		for(int i = 1;i <= n; i++) {
			for(int j = 0;j < i; j++) {
				if(i-j>1 && pre[i]-pre[j] <= n && num[pre[i]-pre[j]]) {
					ans += num[pre[i]-pre[j]];
					num[pre[i]-pre[j]] = 0;
				}
			}
		}
		
		printf("%d\n", ans);
	}
}