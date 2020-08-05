#include <bits/stdc++.h>
using namespace std;

int _, n, a[300005];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		
		if(a[n] > a[1]) puts("YES");
		else puts("NO");
	}
}