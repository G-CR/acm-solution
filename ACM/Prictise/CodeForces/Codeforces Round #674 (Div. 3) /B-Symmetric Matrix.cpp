#include <bits/stdc++.h>
using namespace std;

int _, n, m;
int a, b, c, d;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		bool ok = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d %d %d %d", &a, &b, &c, &d);
			if(b == c) {
				ok = 1;
			}
		}
		if(m % 2) puts("NO");
		else {
			if(ok) puts("YES");
			else puts("NO");
		}
	}
}