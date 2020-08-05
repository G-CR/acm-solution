#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
int c[1005], r[1005];
int mp[1005][1005];
int h, w;

int main() {
	scanf("%d %d", &h, &w);
	for(int i = 1;i <= h; i++) {
		scanf("%d", &r[i]);
	}
	
	for(int j = 1;j <= w; j++) {
		scanf("%d", &c[j]);
	}
	
	int ans = 1;
	for(int i = 1;i <= h; i++) {
		for(int j = 1;j <= w; j++) {
			if(i-1 == c[j] && j-1 < r[i]) return puts("0"), 0;
			if(j-1 == r[i] && i-1 < c[j]) return puts("0"), 0;
			if(j-1 > r[i] && i-1 > c[j]) {
//				printf("j = %d r[i] = %d i = %d c[j] = %d\n", j, r[i], i, c[j]);
				ans = ans*2%mod;
			}
		}
	}
	
	printf("%d\n", ans);
}