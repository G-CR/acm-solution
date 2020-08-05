#include <bits/stdc++.h>
using namespace std;

int q,n;
int num[3000],x;

int main() {
	scanf("%d", &q);
	while(q--) {
		memset(num, 0, sizeof(num));
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			if(x <= 2048) {
				num[x]++;
				if(x <= 1024 && num[x] == 2) {
					int j = 1;
					while(x * j < 2048) {
						if(num[x*j] == 2) {
							num[x*j] = 0;
							num[x*j*2]++;
							j *= 2;
						}
						else break;
					}
				}
			}
		}
		if(num[2048]) puts("YES");
		else puts("NO");
	}
}