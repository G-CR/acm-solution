#include <bits/stdc++.h>
using namespace std;

int _, l, r;

int main() {
	scanf("%d", &_);
	while(_--) {
		int ans = 0;
		scanf("%d %d", &l, &r);
		ans = (int)sqrt(r)-(int)sqrt(l);
		int t = sqrt(l);
		if(t*t == l) ans++;
		printf("%d\n", ans);
	}
}