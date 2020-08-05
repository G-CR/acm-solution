#include <bits/stdc++.h>
using namespace std;

int _, n, m, k, a[105];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
		int now = 0, stair = 1, ans = 0;
		
		while(stair <= n) {
			int can = max(0, m-now); //printf("can = %d\n", can);
			now += min(can, a[stair]); //printf("now = %d\n", now);
			a[stair] = max(0, a[stair]-can); //printf("a[%d] = %d\n", stair, a[stair]);
			if((can-k > 0 || now == 0) && a[stair] == 0) {
				if(now) now += k;
				stair++;
			}
			else {
				ans++;
				now = 0;
			}
//			printf("ans = %d\n\n", ans);
//			getchar();
		}
		if(now) ans++;
		printf("%d\n", ans);
	}
}