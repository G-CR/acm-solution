#include <bits/stdc++.h>
using namespace std;

int T, n, a;

int main() {
	scanf("%d", &T);
	while(T--) {
		int ans = -1;
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a);
			ans = max(ans, a);
		} 
		printf("%d\n", ans);
	}
}