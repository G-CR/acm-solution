#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	int a[2003]; a[0] = 0;
	while(_--) {
		bool ok = 0;
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int l = 0, r = n;
		for(int i = 1; i <= n; i++) {
			a[i] = a[i] ^ a[i-1];
			if(a[i] == 0 && l == 0) {
				l = i;
			}
			if(a[i] == 0) {
				r = i;
			}
		}
		
		int sum = a[n];
		for(int i = 1; i <= l; i++) {
			if(a[i] == sum) {
				ok = 1;
				break;
			}
		}
		if(ok && r) puts("YES");
		else puts("NO");
	}
}