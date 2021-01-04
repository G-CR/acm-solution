#include <bits/stdc++.h>
using namespace std;

int _, n, k, a[100005], num[105];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &k);
		memset(num, 0, sizeof num);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
			num[a[i]]++;
		}
		
		int color, cnt = 0;
		for(int i = 1;i <= 100; i++) {
			if(cnt < num[i]) {
				cnt = num[i];
				color = i;
			}
		}
		
		int ans = 0;
		for(int color = 1;color <= 100; color++) {
			if(!num[color]) continue;
			int i = 1, now = 0;
			while(i <= n) {
				if(a[i] != color) {
					i = i+k-1;
					now++;
				}
				i++;
			}
			ans = min(ans, now);
		}
		
		printf("%d\n", ans);
	}
}