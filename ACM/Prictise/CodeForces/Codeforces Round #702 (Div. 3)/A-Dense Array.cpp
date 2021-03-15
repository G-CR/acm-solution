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
		
		int ans = 0;
		for(int i = 2;i <= n; i++) {
			int ma = max(a[i], a[i-1]);
			int mi = min(a[i], a[i-1]);
			for(int j = mi*2; j < ma; j *= 2) {
				ans++;
			}
		}
		
		printf("%d\n", ans);
	}
}