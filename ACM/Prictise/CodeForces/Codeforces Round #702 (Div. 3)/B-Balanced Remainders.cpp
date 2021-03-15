#include <bits/stdc++.h>
using namespace std;

int _, n;
int a, mod[3];

bool check() {
	return mod[0] == mod[1] && mod[1] == mod[2];
}

int main() {
	scanf("%d", &_);
	while(_--) {
		memset(mod, 0, sizeof(mod));
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a);
			mod[a%3]++;
		}
//		for(int i = 0;i <= 2; i++) printf("%d ", mod[i]); puts("");
		
		int tb = n / 3;
		int ans = 0;
		while(1) {
			for(int i = 0;i <= 2; i++) {
				if(mod[i] < tb) {
//					printf("id = %d\n", i);
					int cha = tb - mod[i];
					int to = min(cha, mod[(i-1+3)%3]);
//					printf("%d\n", to);
					ans += to;
					mod[i] += to;
					mod[(i-1+3)%3] -= to;
				}
			}
			if(check()) break;
		}
		printf("%d\n", ans);
	}
}