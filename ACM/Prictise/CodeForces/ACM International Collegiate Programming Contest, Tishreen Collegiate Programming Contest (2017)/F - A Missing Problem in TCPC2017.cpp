#include <bits/stdc++.h>
using namespace std;

int T, n, x;
int a[15];

int main() {
	scanf("%d", &T);
	while(T--) {
		memset(a, 0, sizeof(a));
		scanf("%d", &n);
		for(int i = 1;i <= n-1; i++) {
			scanf("%d", &x);
			a[x] = 1;
		}
		for(int i = 1;i <= n; i++) {
			if(!a[i]) {printf("%d\n", i); break;}
		}
	}
}