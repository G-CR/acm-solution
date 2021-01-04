#include <bits/stdc++.h>
using namespace std;

int n, a[1003];
bool vis[1003];

int main() {
	scanf("%d", &n);
	for(int i = 1;i <= n; i++) {
		scanf("%d", &a[i]);
	}
	bool ok = 0;
	int ans;
	
	for(int i = 1;; i++) {
		int l = 1, r = l+i-1;
		while(r <= n) {
			int now = 0;
			for(int j = l;j <= r; j++) {
				now = now*10+a[j];
			}
			vis[now] = 1;
			r++; l++;
		}
		if(i == 1) {
			for(int j = 0;j <= 9; j++) {
				if(!vis[j]) {
					ans = j; ok = 1;
					break;
				}
			}
		}
		if(i == 2) {
			for(int j = 10;j <= 99; j++) {
				if(!vis[j]) {
					ans = j; ok = 1;
					break;
				}
			}
		}
		if(i == 3) {
			for(int j = 100;j <= 999; j++) {
				if(!vis[j]) {
					ans = j; ok = 1;
					break;
				}
			}
		}
		if(ok) break;
	}
	printf("%d\n", ans);
}