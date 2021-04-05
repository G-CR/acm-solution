#include <bits/stdc++.h>
using namespace std;

int _, n;
int to[103], go[103], tmp[103];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d %d", &to[i], &go[i]);
		}
		for(int i = 1; i <= n; i++) {
			scanf("%d", &tmp[i]);
		}
		
		int now = 0;
		
		for(int i = 1; i <= n; i++) {
			now += to[i]-go[i-1]+tmp[i];
			int las = ceil((1.0*go[i]-to[i])/2);
			if(i == n) break;
			now += las;
			now = max(now, go[i]);
//			printf("now = %d\n", now);
		}
		
		printf("%d\n", now);
	}
}