#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[105];

int main() {
	while(~scanf("%d %d", &n, &m)) {
		if(!n && !m) break;
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		a[n+1] = m;
		sort(a+1, a+2+n);
		printf("%d", a[1]);
		for(int i = 2;i <= n+1; i++) {
			printf(" %d", a[i]);
		}
		puts("");
	}
}