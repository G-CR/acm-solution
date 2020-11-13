#include <bits/stdc++.h>
using namespace std;

int _, n;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		int ans = 1e9+7;
		for(int i = 0; i < 65000; i++) {
			int now = 1+i;
			int t = (n/now+(bool)(n%now)-1+i);
			ans = min(ans, t);
		}
		printf("%d\n", ans);
	}
}