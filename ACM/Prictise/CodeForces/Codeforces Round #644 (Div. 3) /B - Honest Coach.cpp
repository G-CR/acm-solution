#include <bits/stdc++.h>
using namespace std;

int _, n, a[55];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a+1, a+1+n);
		
		int Min = 2000;
		for(int i = 2;i <= n; i++) {
			Min = min(Min, a[i]-a[i-1]);
		}
		
		printf("%d\n", Min);
	}
}