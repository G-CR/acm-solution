#include <bits/stdc++.h>
using namespace std;

int T, k, m, n;
char a[10004];
int main() {
	scanf("%d", &T);
	while(T--) {
		scanf("%d %d %d", &n, &m, &k);
		for(int i = 1;i <= m; i++) ok[i] = 0;
		for(int i = 1;i <= n; i++) {
			scanf(" %c", &a[i]);
		}
		char x; int num;
		int ans = 0;
		int Max = 0;
		for(int i = 1;i <= m; i++) {
			scanf(" %c", &x);
			if(x == 'W') {
				scanf("%d", &num);
				if(num <= k) ans++;
				else if(num <= Max && a[num] == 'S') ans++;
			}
			else if(x == 'A') {
				Max = n;
			}
			Max = max(num, Max);
		}
		printf("%d\n", ans);
	}
}