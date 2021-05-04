#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[103];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int k = a[1];
		int t = a[2];
		if(k != t) {
			int l = a[3];
			if(k != l) k = l;
		}
		
		int ans = -1;
		for(int i = 1; i <= n; i++) {
			if(a[i]!= k) {
				ans = i;
				break;
			}
		}
		
		printf("%d\n", ans);
	}
}