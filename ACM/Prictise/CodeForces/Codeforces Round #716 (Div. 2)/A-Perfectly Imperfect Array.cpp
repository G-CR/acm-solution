#include <bits/stdc++.h>
using namespace std;

int _;
int n, a[103];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		bool ok = 0;
		for(int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			int k = sqrt(a[i]);
			if(k * k != a[i]) {
				ok = 1;
			}
		}
		if(ok) puts("Yes");
		else puts("No");
	}
}