#include <bits/stdc++.h>
using namespace std;

int _, n, m, a;

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d %d", &n, &m);
		int sum = 0;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a);
			sum += a;
		}
		if(sum == m) puts("YES");
		else puts("NO");
	}
}