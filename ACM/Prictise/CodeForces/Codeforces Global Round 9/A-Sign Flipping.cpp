#include <bits/stdc++.h>
using namespace std;

int _, n;
int a[104];

int main() {
	scanf("%d", &_);
	while(_--) {
		scanf("%d", &n);
		for(int i = 1;i <= n; i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n; i++) {
			if(i%2) printf("%d ", abs(a[i]));
			else printf("%d ", -abs(a[i]));
		}
		puts("");
	}
}