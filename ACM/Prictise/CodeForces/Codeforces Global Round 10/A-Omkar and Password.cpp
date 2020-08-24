#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[200005];

bool check() {
	for(int i = 2;i <= n; i++) {
		if(a[i] != a[i-1]) return 1;
	}
	return 0;
}

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		if(check()) puts("1");
		else printf("%d\n", n);
	}
}