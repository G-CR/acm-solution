#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[105];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int t = a[1]%2;
		bool ok = 1;
		for(int i = 2;i <= n; i++) {
			if(a[i] % 2 != t) {
				ok = 0;
				break;
			}
		}
		if(ok) puts("YES");
		else puts("NO");
	}
}