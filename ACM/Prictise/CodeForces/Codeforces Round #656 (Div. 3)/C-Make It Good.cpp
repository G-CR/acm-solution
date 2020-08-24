#include <bits/stdc++.h>
using namespace std;

int _, n, a[200005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int xiao = 0, da  = 0;
		int ans = 0;
		for(int i = n-1;i >= 1; i--) {
			if(a[i] < a[i+1]) {
				if(da == 1) da = -1;
				if(xiao == -1) {ans = i; break;}
				if(xiao == 0) {
					xiao = 1;
					if(da == 0) da = -1;
				} 
			}
			if(a[i] > a[i+1]) {
				if(xiao == 1) xiao = -1;
				if(da == -1) {ans = i; break;}
				if(da == 0) da  = 1;
			}
		}
		printf("%d\n", ans);
	}
}