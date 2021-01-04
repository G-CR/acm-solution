#include <bits/stdc++.h>
using namespace std;

int _, n, m;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		if(n > m) swap(n, m);
		int ans = 0;
		while(1) {
			if(n == 0 && m == 0) break;
			if(n*2 <= m) {
				n *= 2;
			}
			else {
				m--; n--;
			}
			ans++;
		}
		printf("%d\n", ans);
	}
}