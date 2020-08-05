#include <bits/stdc++.h>
using namespace std;

int _, n, x;
map <int, int> a;

int main() {
	scanf("%d", &_);
	int cas = 0;
	while(_--) {
		a.clear();
		int ans = 0;
		scanf("%d", &n);
		printf("Case %d: ", ++cas);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &x);
			if(a[x] == 0) ans += (x+1);
			a[x]++;
			if(a[x] == x+1) a[x] = 0;
		}
		printf("%d\n", ans);
	}
}