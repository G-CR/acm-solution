#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[55];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		int l = 1;
		for(int i = 1;i <= n; i++) {
			if(a[i] == 1) {
				l = i; break;
			}
		}
		
		int r = n;
		for(int i = n;i >= 1; i--) {
			if(a[i] == 1) {
				r = i; break;
			}
		}
		
		if(l == r) {puts("0"); continue;}
		int ans = 0;
		bool ok = 0;
		for(int i = l+1;i < r; i++) {
			if(a[i] == 0) ans++;
		}
		
		printf("%d\n", ans);
	}
}